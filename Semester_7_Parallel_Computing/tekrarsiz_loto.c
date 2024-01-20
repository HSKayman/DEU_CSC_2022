#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


int main(int argc, char** argv) 
{

	uint32_t i, j, n , e, *dizi, *ek;

    printf("loto n / e, işte yeni şans kodunuz!\n");

    if (argc != 3)
    {
        printf("Eksik argüman!\tÇalıştırma argümanı olarak sırasıyla n ve e (n < e) pozitif tamsayılarını girin!\n");
        return 0;
    }

    n = atoi(argv[1]);
    e = atoi(argv[2]);

    dizi = (uint32_t*) malloc (n * sizeof(uint32_t));
	ek = (uint32_t*) malloc (n * sizeof(uint32_t));
	
	
	for (i = 0; i < n; i++)
		ek[i] = 0;

    srand(time(0));
	
	for (i = 0; i < n; i++)
	{
		dizi[i] = rand() % (e - i) + 1;
		
		for (j = 0; j < i; j++)
			if (dizi[j] - ek[j] <= dizi[i])
				dizi[i]++;
			else
				ek[j]++;
	}
	
	for (i = 0; i < n; i++){
		printf("%u ", dizi[i]);
		printf("%u ", ek[i]);
	}
	printf("\n");
	
	
    return 1;
}