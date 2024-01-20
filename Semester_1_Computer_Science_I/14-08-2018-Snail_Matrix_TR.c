#include<stdio.h>
int main(){
	int i,j,b,q,s=1,a[15][15];
	printf("matrisin boyutunu giriniz : (Girdiginiz sayi 2 ile 15 arasinda olmalidir.)\n\n");
	scanf("%d",&b);
	printf("\n\n");
	if(b>15||b<2){
		printf("Girdiginiz rakam 2 ile 15 arasinda degil");
	}
	for(i=0;i<b;i++){
		for(j=0;j<b;j++){
			a[i][j]=0;
		}
		}
			
	for(q=0;q<=b/2;q++){
		for(j=q;j<b-q;j++){		
			a[q][j]=s;
			s++;
		}
		for (i=1+q;i<b-q;i++){
			a[i][b-1-q]=s;
			s++;
		}
		for (j=b-1-q;j>0+q;j--){
			a[b-1-q][j-1]=s;
			s++;
		}	
		for (i=b-2-q;i>=1+q;i--){
			a[i][q]=s;
			s++;
		}
    }  	
	for (i=0;i<b;i++){
		for(j=0;j<b;j++){
			printf("%d\t",a[i][j]);
		}
	printf("\n");
	}
printf("\nTekrar Baslasin mi? E/H"); scanf("%c",&s);
}
