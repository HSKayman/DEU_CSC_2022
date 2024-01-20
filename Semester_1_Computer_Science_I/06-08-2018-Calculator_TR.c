#include<stdio.h>
int main(){

	float a,b,s;
	l: printf("Hesap makinemize hos geldiniz\n Lutfen Islem yapmak istediginiz iki sayiyi girin:");
	scanf("%f%f",&a,&b);
	
	int i;
	c: printf("Toplama icin :1\nCikarma icin :2\nCarpma icin :3\nBolme icin :4\nLutfen islem turunuzu seciniz:");
	scanf("%d",&i);
	
	switch(i){
		case 1:{s= a+b; break;}
		case 2:{s= a-b; break;}
		case 3:{s= a*b; break;}
		case 4:{s= a/b; break;}
		default:printf("\nyanlis tusa bastiniz"); goto c;
}
	printf("\a\nislem sonucu: %.2f",s);
	int k;
	o: printf("\n\n\ntekrar islem yapmak istiyor musunuz? E/H : \t");
	getchar();
	k=getchar();
	switch(k){
		case 'E': goto l;
		case 'H': break;
		default : printf("yanlis tusa bastiniz"); goto o;
	}
}
