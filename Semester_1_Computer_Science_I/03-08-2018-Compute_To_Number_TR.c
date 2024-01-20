#include<stdio.h>
int main(){
	int a,b;
	printf("2 Sayi Gir:"); scanf("%d%d",&a,&b);
	printf("\nSayilarin Toplamlari:%d\n",a+b);
	printf("Sayilarin Farklari:%d\n",a-b);
	printf("Sayilarin Carpimlari:%d\n",a*b);
	printf("Sayilarin Bolumleri:%f\n",(float)a/(float)b);
	printf("Sayilarin Modlari:%d\n",a%b);
	getchar();
	
}
