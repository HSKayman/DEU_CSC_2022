#include<stdio.h>
#include<stdlib.h>
int main(){
	int **x,i,j,**y,**z,x1,x2,y1,y2,k;
	printf("Lutfen 1.Matrisin Boyutlari Giriniz :");
	scanf("%d %d",&x1,&x2);
	x=(int**)malloc(x1*sizeof(int *));
	for(i=0;i<x1;i++){
		x[i]=(int *)malloc(x2*sizeof(int));
		
		for(j=0;j<x2;j++){
		printf("x[%d][%d] :",i,j);
		scanf("%d",&x[i][j]);
		}	
	}
	printf("\nLutfen 2.Matrisin Boyutlarini Giriniz :");
	scanf("%d %d",&y1,&y2);
	y=(int **)malloc(y1*sizeof(int *));
	for(i=0;i<y1;i++){
		y[i]=(int *)malloc(y2*(sizeof(int)));
		
		for(j=0;j<y2;j++){
		printf("\n y[%d][%d] :",i,j);
		scanf("%d",&y[i][j]);
		}
	}
	if(x2!=y1){
		printf("Lutfen Adam Akilli Matris Girin");
		exit(-1);
	}
	z=(int **)malloc(x1*sizeof(int *));
	for(i=0;i<x1;i++){
		z[i]=(int *)malloc(y2*sizeof(int));
		for(j=0;j<y2;j++){
			for(k=0;k<x2;k++)
				z[i][j]+=x[i][k]*y[k][j];
		}
	}
	for(i=0;i<x1;i++){
		for(j=0;j<y2;j++)
			printf("%d ",z[i][j]);
		printf("\n");
	}
}