#include<stdio.h>
int main(){
	printf("Lutfen sirket sayisini giriniz :"); int s; scanf("%d",&s);
	printf("Lutfen sirkette max calisan kisi sayisini giriniz :"); int c; scanf("%d",&c);
	char sir[s][c][20];    int wallet[s][c];
	for(int i=0;i<s;i++){
		for(int j=0;j<c;j++){
			printf("\nLutfen %d. Sirkette %d. Calisanin Ismini Giriniz: ",i+1,j+1); scanf("%s",&sir[i][j]);
			printf("\nLutfen %d. Sirkette %d. Calisanin Maasini giriniz: ",i+1,j+1); int m; scanf("%d",&m);
			printf("\nLutfen %d. Sirkette %d. Calisanin Saatigi Urunu giriniz: ",i+1,j+1); int u; scanf("%d",&u);
			if(u<5)
			wallet [i][j]=(u*50)+m;
			else
			wallet[i][j]=(u*100)-250+m;
		}
	}
	printf("\n+++++++++++++++++++++++++++++++++++++\n\n");
	
	for(int i=0;i<s;i++){
		printf("\n %d. SIRKET",i+1);
		for(int j=0;j<c;j++){
			printf("\n%s Maasi: %d TL",sir[i][j],wallet[i][j]);
			
		}
	}	
}