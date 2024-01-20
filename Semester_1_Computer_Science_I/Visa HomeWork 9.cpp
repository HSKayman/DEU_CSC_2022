//9
#include<stdio.h>
#include<math.h>

int main(){
	double x,y;
	printf("Lutfen x'i giriniz-->"); scanf("%lf",&x);
	printf("Lutfen y'yi giriniz-->"); scanf("%lf",&y);
	if(y>=(1/2)&&x<=1.2&&x>=-1.2&&y<=cos(x)){
		printf("Bu Noktalarin Icindedir Cizgiler Dahil...");
	}else
		printf("Bu Noktalarin Icinde Degildir...");
}
