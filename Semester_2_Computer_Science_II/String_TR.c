#include<string.h>
#include<stdio.h>
int main(){
	char str1[15];
	char str2[15];
	int r;
	strcpy(str1,"elma");
	strcpy(str2,"elmas");
	r =strcmp(str1,str2);
	if(r<0)
		printf("str1 buyuktur");
	else if(r>0)
		printf("str2 buyuktur");
	else
		printf("esittir");




}