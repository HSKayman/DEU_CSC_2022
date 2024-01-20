
/*
BENİ OKU

Bu programda yalnızca ilk tur rastgele üretimleri gerçekleştirilir.
Her thread kendine ayrılan parçada, birbirinden farklı rastgele sayılar üretir.
Farklı threadlerin ürettiği sayılar aynı olabilir.
Bu parçaları bir araya getirerek sayıların tamamını birbirinden farklı üreten program size  bırakıldı.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <omp.h>

uint8_t icerir(uint32_t *dizi, uint32_t diziBoyutu, uint32_t arananSayi)
{
    uint32_t i;

    for (i = 0; i < diziBoyutu; i++)
        if (dizi[i] == arananSayi)
            return 1;
    
    return 0;
}

int main(int argc, char **argv)
{
    uint32_t i, j, n , e, tsay, *dizi;

    omp_set_dynamic(0);

    //omp_set_num_threads(2); // thread sayısını önceden belirlemek isterseniz, bu satırı kullanabilirsiniz
    
    tsay = omp_get_max_threads();

    printf("loto n / e, işte yeni şans kodunuz!\n");

    if (argc != 3)
    {
        printf("Eksik argüman!\tÇalıştırma argümanı olarak sırasıyla n ve e (n < e) pozitif tamsayılarını girin!\n");
        return 0;
    }

    n = atoi(argv[1]);
    e = atoi(argv[2]);

    dizi = (uint32_t*) malloc (n * sizeof(uint32_t));

    srand(time(0));

    #pragma omp parallel private(i, j) shared(dizi, tsay, n, e)
    {
        uint8_t tid = omp_get_thread_num();

        uint32_t altSinir, ustSinir;

        // threade ayrılan dizi parçasının alt sınırı belirleniyor
        altSinir = tid * (n / tsay);
        
        // üst sınır belirlenirken en büyük numaralı thread'e fazla kalan iş veriliyor
        if (tid == tsay - 1)
            ustSinir = n;
        else
            ustSinir = altSinir + (n / tsay);

        // her threadde rastgele üreten fonksiyona farklı tohum atamak için
        // rastgele üreten fonksiyon thread-güvenli (thread-safe) değilse, istendiği gibi çalışmayabilir!
        srand(time(0) * (tid + 1));

        for (i = altSinir; i < ustSinir; i++)
        {
            dizi[i] = rand() % e + 1;

            // mevcut thread tarafından üretilenler sayılar arasında, yeni üretilen ile aynısı varsa, for döngüsünü 1 adım geri al
            if ( icerir(&dizi[altSinir], i - altSinir, dizi[i]) )
                i--;
        }
        
        printf("thread %u işini bitirdi!\n\n", tid);
    }

    for (i = 0; i < n; i++)
        printf("%u ", dizi[i]);
    
    printf("\n");

    return 1;
}