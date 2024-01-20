//30
#include<stdio.h>
int main(){
	float x,y;
	printf("Lutfen x'i giriniz-->"); scanf("%f",&x);
	printf("Lutfen y'yi giriniz-->"); scanf("%f",&y);
	if(y<x*x&&x<=1&&x>=-1&&y>=0){
		printf("Bu Noktalarin Icindedir Cizgiler Dahil...");
	}else
		printf("Bu Noktalarin Icinde Degildir...");
}
