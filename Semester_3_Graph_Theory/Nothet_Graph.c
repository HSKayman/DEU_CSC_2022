#include<stdio.h>
#include<stdlib.h>
int nothing(int**,int);
int control(int **,int);
int count(int,int **,int);
int main(){
	n1:
	printf("\nLutfen Matrisiniz Ilk Satirinizi (-1) e Basincaya Kadar Giriniz\n");
	int cc=10;
	int *b=(int *)malloc(cc*sizeof(int));
	int i=0;
	do{
		int f;
		printf("\n a[0][%d]: ",i);
		scanf("%d",&f);
		if(f!=-1){
			i++;
			if(cc-1<=i){
				cc+=10;
				b=(int *)realloc(b,cc*sizeof(int));
			}
			b[i-1]=f;
			continue;
		}else
			break;
	}while(1);
		
	int c,v=i;
	int **a=(int **)malloc(v*sizeof(int *));
	a[0]=(int *)malloc(v*sizeof(int));
	
	for(i=0;i<v;i++)
		a[0][i]=b[i];
	free(b);
	
	for(i=1;i<v;i++){
		a[i]=(int *)malloc(v*sizeof(int));
		int j;
		for(j=0;j<v;j++){
			printf("\n a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	if(!control(a,v)){
		printf("\n Matris Yanlis! ,Tekrar Deneyiniz!\n");	
		goto n1;
	}
	nothing(a,v);
	for (i=0;i<v;i++)
		printf("\n%d. Tepenin %d Komsusu Vardir.\n",i,count(i,a,v));
		
}
int count(int j,int **a,int v){
	int i;
	int sum=0;
	for(i=0;i<v;i++)
		sum+=a[j][i];
	return sum;
}
int control(int **a,int v){
	int i,j;
	for(i=0;i<v;i++){
		if(a[i][i]!=0)
			return 0;
		for(j=0;j<v;j++)
			if((a[i][j]!=0&&a[i][j]!=1)||a[i][j]!=a[j][i])
				return 0;
	}
	return 1;
}
int nothing(int **a,int v){
	int i,j;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			if(i!=j)
				a[i][j]=1-a[i][j];
}