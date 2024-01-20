#include<stdio.h>
#include<math.h>
int main (){
	float a,b,c;
	printf("lutfen hipotenusunu bulmak istediginiz dik ucgenin dikey ve yatay uzunluklarini giriniz:"); scanf("%f %f",&a,&b);
	c=  sqrt(pow(a,2)+pow(b,2));
	printf("Hipotenusun uzunlugu bu olmali: %.2f",c);
}
