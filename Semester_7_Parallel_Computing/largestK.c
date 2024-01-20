#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define MAX_SAYI 1000
/*
void enbEkle(uint32_t *dizi, uint32_t diziBoyutu, uint32_t sayi)
{
    uint32_t i, mini;

    for (i = 0; i < diziBoyutu; i++)
        if (dizi[i] < sayi)
            break;
		
	if (i == diziBoyutu)
		return;
	
	mini = i;
    
    for ( ; i < diziBoyutu; i++)
		if (dizi[i] < dizi[mini])
			mini = i;
	
	dizi[mini] = sayi;

    return;
}
*/

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
    uint32_t i, k, n, *dizi, *enbDizi;


    printf("(n) adet sayi icinden en buyuk (k) tanesini bulalim!\n");

    if (argc != 3)
    {
        printf("Eksik argüman!\tÇalıştırma argümanı olarak sırasıyla k ve n (k < n) pozitif tamsayılarını girin!\n");
        return 0;
    }

    k = atoi(argv[1]);
    n = atoi(argv[2]);
    
    dizi = (uint32_t*) malloc (n * sizeof(uint32_t));
    enbDizi = (uint32_t*) malloc (k * sizeof(uint32_t));

    srand(time(0));

    for (i = 0; i < n; i++)
        dizi[i] = rand() % MAX_SAYI;
    
    clock_t zamanBasi = clock();

    for (i = 0; i < k; i++)
    
        enbDizi[i] = dizi[i];
for (i = k; i < n; i++)
        enbEkle(enbDizi, k, dizi[i]);

    double gecenZaman = ((double) (clock() - zamanBasi)) / CLOCKS_PER_SEC;

/*
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%u ", dizi[i]);
    printf("\n");
    
    for (i = 0; i < k; i++)
        printf("%u ", enbDizi[i]);
    printf("\n");
*/

    printf("Gecen zaman = %.2f sn.\n", gecenZaman);

    return 1;
}