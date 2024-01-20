#include <stdio.h>
#include <string.h>
int main(){
	char q[]="ANKARA",a[11];
	printf("Turkiyenin Baskenti Neresidir?"); 
	scanf("%s",&a);
	char b[11];
	strcpy(b,strupr(a));
	if(strcmp(q,b)==0)
		printf("Dogru Cevap...");
	else
		printf("Yanlis Cevap");
}
