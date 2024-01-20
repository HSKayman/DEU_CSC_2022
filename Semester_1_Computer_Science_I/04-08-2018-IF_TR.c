#include<stdio.h>
int main(){
	printf("Lutfen Ekrana farkli 3 sayi giriniz:");
	int i,d,k;
	scanf("%d %d %d",&i,&d,&k);
	if (i>d && i>k){
		printf("En Buyuk Sayi : %d'dir",i);
	} 
	else if(d>i && d>k){
		printf("En Buyuk Sayi : %d'dir",d);
	}
	else{
		printf("En Buyuk Sayi : %d'dir",k);
	}
}