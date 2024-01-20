#include<stdio.h>
int main(){
	int a;
	printf("kac sehir gireceksiniz:"); scanf("%d",&a);
	char city[a][20];
	for(int i=0; i<a; i++){
		printf("%d. sehri giriniz\n",i+1); scanf("%s",city[i]);
	}
	
	
	printf("\nCitys\n");
	for(int i=0; i<a; i++){
		printf("%d. Sehir : %s \n",i+1,city[i]);
	}
}