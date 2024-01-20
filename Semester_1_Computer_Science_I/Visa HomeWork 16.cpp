//16
#include<stdio.h>
int main(){
	float x,y;
	printf("Lutfen x'i giriniz-->"); scanf("%f",&x);
	printf("Lutfen y'yi giriniz-->"); scanf("%f",&y);
	if(((x*x+y*y)<=1)&&((x-2)*(x-2)+(y*y))<=4){
		printf("Bu Noktalarin Icindedir Cizgiler Dahil...");
	}else
		printf("Bu Noktalarin Icinde Degildir...");
}
