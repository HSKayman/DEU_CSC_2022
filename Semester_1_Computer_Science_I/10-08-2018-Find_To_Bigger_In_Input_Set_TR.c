#include<stdio.h>
int main(){
	int a=0,b=0,c=0;
	printf("Lutfen girdiginiz sayilarin en buyugu bulmak icin -1 tusuna basana kadar sayi girin");
	while(a<9999999){
			scanf("%d",b);
		if(b>c){
		c=b;}
		printf("\n Guncel en buyuk sayi:%d",c);
		a++;
	}
	printf("\n\aEn guncel en buyuk sayi:%d",c);
}
