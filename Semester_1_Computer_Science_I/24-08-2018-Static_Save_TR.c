#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int credi;
	char isim[10];
}lesson;

int main(){
	printf("Statik Kayit Etmeye Hosgeldiniz\n************************\n'-1' e basana kadar kayit edebilirsiniz.");
	lesson *a[99];
	int *p; int i;
	p=&i;
	char b[i][30];
	printf("\nKac Ders Gireceginizi giriniz :"); int ay; scanf("%d",&ay);
	for(int j=0;j<ay;j++){
		printf("\n%d. Dersi Giriniz :",j+1);
		scanf("%s",&a[j]->isim);
	}
	printf("\nKac Ogrenci Gireceginizi giriniz :"); int aq; scanf("%d",&aq);
	for(i=0;i<aq;i++){
		printf("\n++++++++++++++++++++++++++\n\n %d. Ogrencinin Adi :",i+1);
		scanf("%s",&b[i]);
		for(int k=0;k<ay;k++){
		printf("\n\n %d. Ogrencinin %s dersi kredisi :",i+1,a[i]->isim);
		scanf("%d",&a[i]->credi);	
	}}
	
} 