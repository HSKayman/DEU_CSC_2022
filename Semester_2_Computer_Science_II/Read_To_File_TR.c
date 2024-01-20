#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	FILE *p;
	printf("Dosyanin Adi girin.\n");
	char b[300];
	scanf("%s",b);
	p=fopen(b,"w");
	char a[300],c[300];
	if(!p)
		printf("Dosya Acilmadi");
	getchar();	
	scanf("%[^\n]s",a);
	fprintf(p,"%s",a);
	fclose(p);
	p=fopen(b,"r");
	if(!p)
		printf("\nDosya Okumadi");
	fscanf(p,"%[^\n]s",c);
	printf("%s",c);
	fclose(p);
}