#include<stdio.h>
int main(){
	cb: ;
	int a;
	printf("\n 1-5 arasinda bir sayi giriniz:");
	scanf("%d",&a);
	
	switch(a){
		case 1: printf("1'e bastiniz."); break;
		case 2: printf("2'e bastiniz."); break;
		case 3: printf("3'e bastiniz."); break;
		case 4: printf("4'e bastiniz."); break;
		case 5: printf("5'e bastiniz."); break;
		default : printf("Yanlis Tusa Bastiniz"); 
		goto cb; break;
		
	}
	aqw:
	printf("1-3 arasinda bir deger giriniz."); scanf("%d",&a);
	
	switch(a){
		case 1: printf("%d'ye bastiniz.",a); break;
		case 2: printf("%d'ye bastiniz.",a); break;
		case 3: printf("%d'ye bastiniz.",a); break;
		default : printf("yanlis bastiniz tekrar deneyin."); goto aqw;
		
	}
	
}
