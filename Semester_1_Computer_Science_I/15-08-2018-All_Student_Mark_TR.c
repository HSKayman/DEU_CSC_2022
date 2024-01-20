#include<stdio.h>
int main(){
	printf("\nSinif Sayisi :"); int s,v,f; scanf("%d",&s);
	printf("\nHer hangi bir sinif icin en fazla Ogrenci sayisi :"); int o; scanf("%d",&o);
	char std[s][o][20]; int ogr[s][o];
	printf("\n\nKayit Etmeye baslayiniz :");
	for(int i=0; i<s; i++){
		for(int j=0;j<o;j++){
			printf("\n%d. siniftaki %d. siradaki ogrencinin adi :",i+1,j+1); scanf("%s",&std[i][j]);
			printf("\n%d. siniftaki %d. siradaki %s adli ogrencinin vize notu :",i+1,j+1,std[i][j]); scanf("%d",&v);
			printf("\n%d. siniftaki %d. siradaki %s adli ogrencinin final notu :",i+1,j+1,std[i][j]); scanf("%d",&f);
			ogr[i][j]=(float)((float)v*0.4+(float)f*0.6);
		}
	}
	printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	for(int i=0;i<s;i++){
		printf("\n%d SINIFINDAKI OGRENCILER\n",i+1);
		for(int j=0;j<o;j++){
			if(ogr[i][j]<50)
			printf("%d. siniftaki %d. siradaki %s adli ogrenci %d puanla kalmistir.\n",i+1,j+1,std[i][j],ogr[i][j]);
			else
			printf("%d. siniftaki %d. siradaki %s adli ogrenci %d puanla gecmistir.\n",i+1,j+1,std[i][j],ogr[i][j]);
		}
		printf("\n\n\n\t");
	}
	
	
}