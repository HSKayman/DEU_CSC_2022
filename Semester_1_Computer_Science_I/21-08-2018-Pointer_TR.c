#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *gunismi(char *gundizisi[],int hangigun){
	if(hangigun>=1 && hangigun<=7){
		return gundizisi[hangigun-1];
	}
	else{
	return NULL;}
}

int main(){
	
	char *gunler[4]={"pazartesi","sali","carsamba"};
	
	char *p;
	p= gunismi(gunler,2);
	printf("%s",p);
}   