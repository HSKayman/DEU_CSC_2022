#include <stdio.h>
#include <string.h>
int main(){
	char user[3][10],sifre[3][10],user2[10],sifre2[10];
	printf("2 tane uyelik giriniz");
	int k=0;
	while(k<2){
	printf("Kullanici Adiniz: "); scanf("%10s",&user[k]);
	printf("Sifre: "); scanf("%10s",&sifre[k]);
	k++;
	}
	q1: printf("\n\n\n\nKullanici Adiniz: "); scanf("%10s",&user2);
	printf("Sifre: "); scanf("%10s",&sifre2);
	for(int i=0;i<4;i++){
	if(strcmp(user[i],user2)==0 && strcmp(sifre[i],sifre2)==0){
		printf("giris basarili");
	}
	else if(strcmp(user[i],user2)!=0 && strcmp(sifre[i],sifre2)!=0){
		printf("giris basarisiz tekrar deneyiniz."); goto q1;
	}
}}