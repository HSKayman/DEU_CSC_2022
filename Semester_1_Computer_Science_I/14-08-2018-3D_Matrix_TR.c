#include<stdio.h>
int main(){
	int school[2][2][5];
	int f,v,j;
	for(int i=0; i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<5;k++){
				printf("Lutfen %d. okuldaki %d. sinifindaki %d. ogrencinin vize notunu giriniz.",i+1,j+1,k+1); scanf("%d",&v);
				printf("Lutfen %d. okuldaki %d. sinifindaki %d. ogrencinin final notunu giriniz.",i+1,j+1,k+1); scanf("%d",&f);
				school[i][j][k]=((v+v)+(f+f+f))/5;
			}
		}
	}
	printf("\n\n\n\n\n");
	int i=0;
	while(i<2){
		int j=0;
		printf("%d. OKUL\n",i+1);
		
		while(j<2){
			int k=0;
				printf("%d. SINIF\n",j+1);
			while(k<5){
				if(school[i][j][k]<50)
				printf("%d. okuldaki %d. sinifindaki %d. ogrenci %d puanla kalmistir.\n",i+1,j+1,k+1,school[i][j][k]);
				else
				printf("%d. okuldaki %d. sinifindaki %d. ogrenci %d puanla gecmistir.\n",i+1,j+1,k+1,school[i][j][k]);
				k++;
			}
			printf("\n\n");
			j++;
		}
		printf("\n\n\n\n");
		i++;
	}}