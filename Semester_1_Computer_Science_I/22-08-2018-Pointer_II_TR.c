#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char isim[20];
	char *a;
	scanf("%s",isim);
	a=isim;
	printf("\n\n\n\n\n %s",a);
	char ad[20]="Deneme Mesaji";
	char b[20]="ilk mesaj";
	char *ap=ad;
	char *bp=b;
	printf("%s %s",ap,bp);
	ap =bp;
	printf("%s %s",ap,bp);
	char isim2[20];
	char *soyisim;
	soyisim= (char*) malloc(sizeof(char)*20);
	scanf("%s",isim2);
	scanf("%s",soyisim);
	printf("tanistigimiza memnum oldum %s %s",isim2,soyisim);
}