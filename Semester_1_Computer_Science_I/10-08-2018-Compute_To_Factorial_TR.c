#include<stdio.h>
int main(){
	int a=0,b=1;
	long int c=1;
	printf("fakrotiyelini hesaplamak istediginiz sayiyi girin :"); scanf("%d",&a);
	while(b<=a){
		c=c*b;
		b++;
		
	}
	printf("%d'nin faktoriyeli: %d",a,c);
}