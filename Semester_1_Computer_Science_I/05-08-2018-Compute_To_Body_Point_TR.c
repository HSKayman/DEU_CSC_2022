#include<stdio.h>
int main(){
	
	char c ;
	printf("Lutfen cinsiyetinizi numara araciligiyla giriniz [E/K]: "); scanf("%c",&c);
	if(c=='K'){
		float kb;
				printf("Lutfen Boyunuzu Metre Cinsinden Giriniz:"); scanf("%f",&kb);
		
		if(kb<0.50 || kb>2.50){
				printf("Boyunuzun Boyle Olmasi imkansiz reddedildiniz.");
		}
		else if(kb>=1.70){
				printf("Basketbol Takimina Adayliginiz kaydedilmistir.");
		}
		else{
				printf("Maalesef Sartlarimiza gore boyunuz kucuk gelmistir. \nKaydiniz yapilmamistir.");
		}
	}
	else if(c=='E'){
		float eb;
				printf("Lutfen Boyunuzu Metre Cinsinden Giriniz:"); scanf("%f",&eb);
		
		if(eb<0.50 || eb>2.50){
				printf("Boyunuzun Boyle Olmasi imkansiz reddedildiniz.");
		}
		else if(eb>1.79){
				printf("Basketbol Takimina Adayliginiz kaydedilmistir.");
		}
		else{
				printf("Maalesef Sartlarimiza gore boyunuz kucuk gelmistir. \nKaydiniz yapilmamistir.");
		}
	}
	else{
				printf("Lutfen Cinsiyetinizi Kontrol Edip Giriniz.");
	}
	return 0;
}
