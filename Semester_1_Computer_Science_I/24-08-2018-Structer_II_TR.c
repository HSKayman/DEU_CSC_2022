#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{
	bay,
	bayan
}cinsiyet;
typedef struct{
	int yas;
	char *isim;
	cinsiyet c;
}insan;
int main(){
	insan *veli;
	veli=(insan*)malloc(sizeof(insan));
	veli ->yas=12;
	veli ->c=bay;
	printf("%u cinsiyetli velinin yasi %d",veli->c,veli->yas);
}