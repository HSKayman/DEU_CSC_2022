#include<stdio.h>
int fib(int);
int main(){
	as: int a;
	printf("lutfen sayi giriniz: "); scanf("%d",&a);
	printf("\n girdiginiz sayinin fibonacci serisindeki yeri: %d\n",fib(a));
	goto as;
}
int fib(int x){
	if(x==1 || x==2){
	
		return 1; }
	else {
	
return fib(x-1)+fib(x-2);}
}