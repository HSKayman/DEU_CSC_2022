#include <stdio.h>
int main(){
	char isim[20],okul[20],bolum[50];
	printf("Ad Soyad :"); gets(isim);
	printf("Okulunuz :"); gets(okul);
	printf("Bolumunuz :"); gets(bolum);
	FILE *dosya;
	dosya =fopen("ogrencibilgi.txt","a");
	fprintf(dosya,"\n%s\t%s\t%s",isim,okul,bolum);
	FILE *dosya2;
	dosya2 =fopen("ogrencibilgi.txt","r");
		int i=0;
		char k[50][20];
		while(!feof(dosya2)){
			fscanf(dosya2,"%s",&k[i]);
			printf("%s ",k[i]);
			i++;
		}
		fclose(dosya2) ;	
	FILE *file2;
	file2=fopen("ogrencibilgi.txt","r");
	char numara[5][40],sinif[5][40],isim[40][40];
	int i=0,j=0;
	if(file2!=NULL){
	while(!feof(file2)){
		fscanf(file2,"%s",&numara[i]);
		fscanf(file2,"%s",&isim[j]);
		fscanf(file2,"%s",&isim[j+1]);
		fscanf(file2,"%s",&isim[j+2]);
		fscanf(file2,"%s",&sinif[i]);
		printf("%s\t\t%s %s %s\t\t%s\n",numara[i],isim[j],isim[j+1],isim[j+2],sinif[i]);
		i++;
		j+=3;
	}}else{
		printf("dosya acilamadi yada bulunamadi.");
	}
	}