#include<stdio.h>
int main(){
	int a,b,c;
	printf("Input To 3 Number \n:"); scanf("%d",&a);
	printf("\nb:"); scanf("%d",&b);
	printf("\nc:"); scanf("%d",&c);
	printf("\nb<a<c \t : %d",(b<a && a<c)||(c<a && a<b));
	printf("\na=b<c \t : %d",a==b && a<c);
	printf("\na>b, a>c \t : %d",a>b && a>c);
	printf("\na=b=c \t : %d",a==b && a==c);
}
