//20
#include<stdio.h>
int main(){
	float x,y;
	printf("Lutfen x'i giriniz-->"); scanf("%f",&x);
	printf("Lutfen y'yi giriniz-->"); scanf("%f",&y);
	if((x<=2)&&(x>=-2)&&(y<2)&&((y>x+2)||(y>=2-x))){
		printf("Bu Noktalarin Icindedir Cizgiler Dahil...");
	}else
		printf("Bu Noktalarin Icinde Degildir...");
}
