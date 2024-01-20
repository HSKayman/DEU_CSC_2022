//13
#include<stdio.h>
#include<math.h>
int main(){
	float x,y;
	printf("Lutfen x'i giriniz-->"); scanf("%f",&x);
	printf("Lutfen y'yi giriniz-->"); scanf("%f",&y);
	if((y>=-sqrt(x))&&(y<=sqrt(x))){
		printf("Bu Noktalarin Icindedir Cizgiler Dahil...");
	}else
		printf("Bu Noktalarin Icinde Degildir...");
}
