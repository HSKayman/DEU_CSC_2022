#include<stdio.h>
int main(){
	printf("Lutfen Notunuzu giriniz:"); int a; scanf("%d",&a);
	if(a>100 || a<0){
		printf("Yanlis islem yaptiniz Lutfen Tekrar Deneyiniz.");
	}
	else if(90<=a){
		printf("%d puani ile Notunuz AA",a);
	}
	else if(80<=a){
		printf("%d puani ile Notunuz BA",a);
	}
	else if (70<=a){
		printf("%d puani ile notunuz BB",a);
	}
	else{
		printf("%d puani ile notunuz F",a);
	}

}
