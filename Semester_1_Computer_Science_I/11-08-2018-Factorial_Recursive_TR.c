#include<stdio.h>
int f(int);
int main(){
	as: int a;
	printf("lutfen sayi giriniz: "); scanf("%d",&a);
	printf("\n girdiginiz sayinin faktoriyeli: %d\n",f(a));
	goto as;
}
int f(int x){
	 if(x==0)
	 return 1;
	 return x*f(x-1);
	}