#include <stdio.h>
#include <string.h>
int main(){
	q1: char capital[]="Ankara",ques[10];
	printf("Turkiyenin baskenti neresidir? :"); scanf("%s",&ques);
	
	if(strcmp(capital,ques)==0 ){
		printf("Dogru bildiniz");
	} 
	else{
	printf("Tekrar deneyiniz"); goto q1;
}}