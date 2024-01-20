#include<stdio.h>
int main(){
	int v,f;
	printf("Lutfen Vizenizi Giriniz  :"); scanf("%d",&v);
	printf("Lutfen Finalinizi Giriniz:"); scanf("%d",&f);
	float o = 0.4*v + 0.6*f;
	
    if( o>100.0 || o<0.0 ){
		printf("Yanlis islem yaptiniz Lutfen Tekrar Deneyiniz.");
	}
	else if(90.0<=o){
		printf("%.2f puani ile Notunuz AA",o);
	}
	else if(80.0<=o){
		printf("%.2f puani ile Notunuz BA",o);
	}
	else if (70.0<=o){
		printf("%.2f puani ile notunuz BB",o);
	}
	else{
		printf("%.2f puani ile notunuz F",o);
	}
}
