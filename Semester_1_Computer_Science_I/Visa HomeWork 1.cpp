//1
#include<stdio.h>
int main(){
	float x,y;
	printf("Lutfen x'i giriniz-->"); scanf("%f",&x);
	printf("Lutfen y'yi giriniz-->"); scanf("%f",&y);
	if(x<=1&&x>=-1&&y<=1&&y>=-1&&(y>=x+1||y>=1-x||y<=x-1||y<=-x-1)){
		printf("Bu Noktalarin Icindedir Cizgiler Dahil...");
	}else
		printf("Bu Noktalarin Icinde Degildir...");
}
