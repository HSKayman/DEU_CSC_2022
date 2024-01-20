#include<stdio.h>
int main(){
	char c;
	int t;
	printf("Lutfen Cinsiyetinizi Giriniz: [E/K]:"); scanf("%c",&c);
	printf("Lutfen Boyunuzu Santimetre Cinsinden Giriniz:"); scanf("%d",&t);
	
	if(c=='E' && t>=180){
		printf("Erke Basketbol Takimina Kaydiniz Uygun Boyunuz:%d",t);
	}
	else if(c=='K' && t>=170){
		printf("Kiz Basketbol Takimina Kaydiniz Uygun Boyunuz:%d",t);
	}
	else if (((c!='E') && (c!='K')) || ((t<50) || (t>250))){
		printf("Lutfen girdiginiz bilgileri kontrol edip tekrar deneyiniz.");
	}	
	else{
		printf("Sartlarimiza Uygun Degilsiniz. Kaydiniz Ipta Edildi");
	}
	
}
