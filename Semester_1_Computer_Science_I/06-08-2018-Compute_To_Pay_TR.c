#include<stdio.h>
int main(){
	int m, u;
	printf("Lutfen maasinizi giriniz :"); scanf("%d",&m);
	printf("Lutfen prim icin urettiginiz urun sayisini giriniz:"); scanf("%d",&u);
	if(u<0){
		printf("Yanlis bilgi girdiniz.");
	}
	else if(u<=10){
		printf("Alacaginiz maas: %d",m+u*5);
	}
	else if(u<=20){
		printf("Alacaginiz maas: %d",m+10*u-50);
	}
	else if(u>20){
		printf("Alacaginiz maas: %d",m+15*u-150);
	}
}
