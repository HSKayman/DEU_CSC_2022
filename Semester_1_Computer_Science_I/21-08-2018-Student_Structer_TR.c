#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct ogrenciler
{
	char ad[20];
	char bolum[50];
	int sinif;
	float ort;
};


int main(){
	struct ogrenciler k;
	struct ogrenciler *kp;
	kp=&k;
		printf("Lutfen  ogrencinin adini giriniz :"); scanf("%s",&k.ad);
		printf("Lutfen  ogrencinin bolumunu giriniz :"); scanf("%s",&k.bolum);
		printf("Lutfen  ogrencinin sinifini giriniz :"); scanf("%d",&k.sinif);
		printf("Lutfen  ogrencinin ortalamasini giriniz :"); scanf("%f",&k.ort);
		printf("%s\t\t%s\t\t%d\t\t%.2f",kp->ad,kp->bolum,kp->sinif,kp->ort);
	
}