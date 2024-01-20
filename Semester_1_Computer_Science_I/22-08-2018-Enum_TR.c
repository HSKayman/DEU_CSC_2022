#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum{
	bay,
	bayan
}cinsiyet;
typedef enum{
	pazartesi,
	sali,
	carsamba,
	persembe,
	cuma,
	cumartesi,
	pazar	
}gunler;

typedef struct{
	int yas;
	char *isim;
	cinsiyet c;	
	gunler f;
} insan;

int main(){
	insan ali;
	insan *a;
	a =(insan*) malloc(sizeof(insan));
	ali.yas=30;
	a->yas= 17;
	ali.f= cuma;
	printf("alinin yasi : %d",ali.yas);
	printf("\nanin yasi : %d",a->yas);
	if(ali.f==4)
	printf("\nalinin gunu : cuma");
	if(ali.c==0)
	printf("\nalinin cinsiyeti : bay");
}