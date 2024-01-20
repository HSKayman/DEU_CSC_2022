#include<stdio.h>
int f(int);
int c(int,int);
int main(){
	int a,b;
	printf("Lutfen iki sayi giriniz: "); scanf("%d%d",&a,&b);
	printf("\n %d sayisinin faktoriyeli : %d\n %d sayisinin %d sayisiyla combinasyonu %d",a,f(a),b,a,c(a,b));
	 
}
int f(int x){
	int s=1,i;
	for(i=1;i<=x;i++){
		s*=i;
	}
	return s;
}
int c(int x,int y){
	return f(x)/((f(y)*f(x-y)));
}
