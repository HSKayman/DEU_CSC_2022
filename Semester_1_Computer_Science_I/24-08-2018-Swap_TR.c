#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yerdegistir(int *x,int *y){
	int swap;
	swap=*x;
	*x=*y;
	*y=swap;
}
int main(){
	int d,d2; 
	printf("iki deger giriniz :"); scanf("%d%d",&d,&d2);
	printf("Oncesi : %d -%d",d,d2);
	yerdegistir(&d,&d2);
	printf("\nSonrasi : %d - %d",d,d2);	  
}