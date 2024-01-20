#include <stdio.h>
int main(){
int a,b=0,c=9999999999;
while(b!=-1){
	printf("Sayi giriniz.");
	scanf("%d",&a);
	if(a>=b)
		b=a;
	if(a<=c)
		c=a;
	printf("\nEn guncel sayi:%d\n",b);
	printf("\nGuncel en kucuk sayi %d\n",c);
}
}
