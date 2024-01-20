#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(void){
	int b,c;
	printf("Programa Hosgeldiniz.");getchar();
	printf("+++++++++++++++++++++++++++++++++++++++++++++++\nAklinizdan sayi tutunuz ve ben bu sayiyi en kisa bir sekilde bulmaya calisacagim.");
	getchar();
	printf("Aklinizdan Simdi Sayi tutunuz.");
	getchar();
	system("CLS");
	printf("\nSayiniz Kac Basamakli :"); int a; scanf("%d",&a);
	int s=(log2(pow(10,a)))+1;
	printf("\nmax %d adimda tuttugunuz sayiyi tahmin edecegim.\n\n\n\n\n",s);
	b=pow(10,a-1);
	c=pow(10,a);
	for(int i=0;i<s;i++){
	q2: printf("%d sayisindan kucuk mu buyuk mu ?[K/B/E]:",(b+c)/2); getchar(); char jaq; int f=(b+c)/2;
	jaq=getchar(); 
	switch(jaq){
		case 'k': c=f; break;
		case 'K': c=f; break;
		case 'B': b=f; break;
		case 'b': b=f; break;
		case 'e': printf("Cevap:%d\t",f); goto q1;
		case 'E': printf("Cevap:%d\t",f); goto q1;
		default: printf("Yanlis Tusa Bastiniz Tekrar Deneyiniz..",f); goto q2;
	}}
	q1: return 0;}
	
