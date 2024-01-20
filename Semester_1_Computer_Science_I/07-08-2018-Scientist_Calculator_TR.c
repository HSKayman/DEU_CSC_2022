#include<stdio.h>
int main(){
	q34: printf("Dort Islem Icin 1'e Basiniz.\nOzel Matematik Islemi Icin 2'ye Basiniz\n\n:");
	int s;
	scanf("%d",&s);
	switch(s){
		case 1:{
			float q,w;
			int e;
			q1: printf("\nIslem yapmak icin istediginiz iki sayiyi giriniz:"); scanf("%f%f",&q,&w);
			getchar();
			printf("\nToplama Icin: 1\nCikarma Icin :2\nCarpma Icin :3\nBolme Icin:4\n\n Lutfen secim yapiniz :"); scanf("%d",&e);
			if(e<1 ||e>5){ 
				printf("\nHatali Islem Yaptiniz, Lutfen Tekrar Deneyin");
			goto q1;
			}
			else if(e==1){
				printf("\n\aCevap :%.2f",q+w);
			}
			else if(e==2){
				printf("\n\aCevap :%.2f",q-w);
			}
			else if(e==3){
				printf("\n\aCevap :%.2f",q*w);
			}
			else if(e==4){
				printf("\n\aCevap :%.2f",q/w);
			}
			goto q2;
		}
		case 2:{
			q56: float q,w;
			int e;
			printf("\nKarekok Almak Icin :1\n Uslu islem yapmak icin :2\n\n secim yapiniz:"); scanf("%d",&e);
			if(e==1){
				printf("\nLutfen karekokunu alma istediginiz sayiyi girin:"); scanf("%f",&q);
				printf("\n\a Cevap :%.2f",sqrt(q));
				goto q2;		
			}
			else if(e==2){
				printf("\nLutfen Us giriniz:"); scanf("%f",&q);
				printf("\nLutfen Taban giriniz:"); scanf("%f",&w);
				printf("\n\a Cevap :%.2f",pow(w,q));
				goto q2;
			}
			else{
				printf("\nYanlis islem yaptiniz, Lutfen tekrar deneyin");
				goto q56;
			}
			break;
		}
		default : printf("\nHatali Islem yaptiniz, Lutfen tekrar deneyin."); goto q34;
	}
	q2: 
	getchar();
	char j;
	printf("\nTekrar Hesap Makinesini Calistirmak Ister misiniz? [E/H] :"); scanf("%c",&j);
	if(j=='E'){
		goto q34;
	}
	else if(j=='H'){
		goto w23;
	}
	else if(j!='E' && j!='H'){
		printf("Hatali Islem yaptiniz lutfen tekrar deneyin.");
		goto q2;
	}
	w23: printf("Saglicakla Kalin.");	
}
