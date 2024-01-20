#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <omp.h>

#define MAX_SAYI 1000

void enbEkle(uint32_t *dizi, uint32_t diziBoyutu, uint32_t sayi)
{
    uint32_t i, mini;

	mini = 0;
    
    for (i = 1; i < diziBoyutu; i++)
		if (dizi[i] < dizi[mini])
			mini = i;
	
	if (sayi > dizi[mini])
		dizi[mini] = sayi;

    return;
}

int main(int argc, char **argv)
{
    uint32_t i, k, n, tsay, *dizi, **enbDiziler;

    omp_set_dynamic(0);

    omp_set_num_threads(4); // thread sayısını önceden belirlemek isterseniz, bu satırı kullanabilirsiniz
    
    tsay = omp_get_max_threads();

    printf("(n) adet sayi icinden en buyuk (k) tanesini bulalim!\n");

    if (argc != 3)
    {
        printf("Eksik argüman!\tÇalıştırma argümanı olarak sırasıyla k ve n (k < n) pozitif tamsayılarını girin!\n");
        return 0;
    }

    k = atoi(argv[1]);
    n = atoi(argv[2]);
    
    dizi = (uint32_t*) malloc (n * sizeof(uint32_t));
    enbDiziler = (uint32_t**) malloc (tsay * sizeof(uint32_t*));

    srand(time(0));

    for (i = 0; i < n; i++)
        dizi[i] = rand() % MAX_SAYI;
	
	/*
	printf("\n");
    for (i = 0; i < n; i++)
        printf("%u ", dizi[i]);
    printf("\n");
    */
	
    double zamanBasi = omp_get_wtime();

	#pragma omp parallel private(i)
	{
		uint32_t tid = omp_get_thread_num();
		
		enbDiziler[tid] = (uint32_t*) malloc (k * sizeof(uint32_t));

		for (i = 0; i < k; i++)
			enbDiziler[tid][i] = 0;

		#pragma omp for
		for (i = 0; i < n; i++)
			enbEkle(enbDiziler[tid], k, dizi[i]);
		
		for (i = 0; i < k; i++)
			dizi[i + k * tid] = enbDiziler[tid][i];
		
		#pragma omp barrier
		
		if (tid == 0)
			for (i = k; i < k * tsay; i++)
				enbEkle(enbDiziler[tid], k, dizi[i]);
	}

    double gecenZaman = omp_get_wtime() - zamanBasi;
	/*
    for (i = 0; i < k; i++)
        printf("%u ", enbDiziler[0][i]);
    printf("\n");
	*/
    printf("Gecen zaman = %.2f sn.\n", gecenZaman);

    return 1;
}