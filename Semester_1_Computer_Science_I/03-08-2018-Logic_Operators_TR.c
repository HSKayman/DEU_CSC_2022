#include<stdio.h>
int main(){
	int a,b;
	printf("2 Sayi Gir:"); scanf("%d%d",&a,&b);
	printf("\nSayilar Esit mi:%d\n",a==b);
	printf("Sayilar Esit Degil mi:%d\n",a!=b);
	printf("Ilk Sayi mi buyuk:%d\n",a>b);
	printf("Ilk Sayi mi kucuk:%d\n",a<b);
	printf("Ilk Sayi mi esit veya buyuk:%d\n",a>=b);
	printf("Ilk Sayi mi esit veya kucuk:%d\n",a<=b);
	getchar();
}
