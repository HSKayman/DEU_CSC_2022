#include<stdio.h>
int k(int);
int main(){
	as: int a;
	printf("lutfen sayi giriniz: "); scanf("%d",&a);
	printf("\n girdiginiz kose boylu karenin icinde toplam kare sayisi: %d\n",k(a));
	goto as;	
}
int k(int x){
	if(x==1)
		return 1;
	return x*x+k(x-1);
}