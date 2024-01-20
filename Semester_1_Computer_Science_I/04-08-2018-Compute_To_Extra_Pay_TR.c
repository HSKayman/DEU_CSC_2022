#include<stdio.h>
int main(){
	printf("Lutfen Yaptiginiz Mesai Saatini giriniz:");
	int a;
	scanf("%d",&a);
	if(a<=10 && a>=0){
		printf("Alacaginiz Para :%d",a*5);
	}
	else if(a<=20){	
		int b = 3*a+20;
		printf("Alacaginiz Para :%d\n Emeklerinize saglik",b);
}
	else if(a>20){
		int c = a*2+40;
		printf("Alacaginiz Para:%d\n Harika Iscimsin",c);
	}
	else{
		printf("Hatali Islem girdiniz Lutfen Tekrar deneyin.");
		
	}
}
