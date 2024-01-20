#include<stdio.h>
int main(){
		printf("Dizinin Eleman Sayisi :"); int f; scanf("%d",&f);
	int d[f];
	printf("%d Tane Eleman Giriniz.\n");
	int i=0;
	while(i<f){
		printf("\n%d. Eleman :",i+1); scanf("%d",&d[i]);
		i++;
	}
	q1: system("CLS"); printf("Kucukten buyuge dizilsin mi? [E/H]\n"); char y[2]; scanf("%c",&y);
	switch(getchar()){
		case 'E':{for(int i=0;i<f-1;i++){
			for(int j=0;j<f-i;j++){
				if(d[j]>d[j+1]){
			int g=0;
			g=d[j];
			d[j]=d[j+1];
			d[j+1]=g;
			}
		}
		}
		break ;}
		case 'H': printf("Islem Basarili\n"); break;
		default: printf("Yanlis islem yaptiniz Tekrar deneyin.\n"); goto q1;
}

for(int i=0;i<f;i++){
	printf("%d \n",d[i]);
	
}	}