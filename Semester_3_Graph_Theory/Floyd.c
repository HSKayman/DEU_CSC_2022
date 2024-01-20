#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
void floydWarshall(int **,int);
void printSolution(int **,int);
bool control(int **,int);
int main(){ 
	/*n1:
	printf("\nLutfen Matrisiniz Ilk Satirinizi (-1) e Basincaya Kadar Giriniz Belli Olmayanlara -2 Giriniz\n");
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
			if(f!=-2)
				b[i-1]=f;
			else
				b[i-1]=SHRT_MAX;
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
			int f;
			scanf("%d",&f);
			if(f!=-2)
				a[i][j]=f;
			else
				a[i][j]=SHRT_MAX;
		}
	}
	
	if(!control(a,v)){
		printf("\n Matris Yanlis! ,Tekrar Deneyiniz!\n");	
		goto n1;
	}*/
	int v=6;
	int b[6][6]={
				{0,7,4,SHRT_MAX,2,SHRT_MAX},
				{7,0,3,2,SHRT_MAX,6},
				{4,3,0,8,1,SHRT_MAX},
				{SHRT_MAX,2,8,0,10,3},
				{2,SHRT_MAX,1,10,0,SHRT_MAX},
				{SHRT_MAX,6,SHRT_MAX,3,SHRT_MAX,0}
	};
	int i,**a=(int **)malloc(v*sizeof(int *));
	for(i=0;i<6;i++){
		a[i]=(int *)malloc(v*sizeof(int));
		int j;
		for(j=0;j<v;j++)
			a[i][j]=b[i][j];
	}
  floydWarshall(a,v); 
  return 0; 
	}

void print(int **a,int v) 
{ 
	int i,j;
  	for(i=0;i<v;i++){ 
    	for(j=0;j<v;j++)
        	if(a[i][j]==SHRT_MAX) 
        	    printf("%7s", " "); 
       		else
            	printf ("%7d", a[i][j]); 
    	printf("\n"); 
  	}	 
}
void floydWarshall (int **a,int v){
	int i,j,k; 
	for(k=0;k<v;k++) 
	    for(i=0;i<v;i++)
	      	for(j=0;j<v;j++) 
	        	if(a[i][k] != SHRT_MAX && 
     				a[k][j] != SHRT_MAX && 
     				a[i][k] + a[k][j] < a[i][j]) 
	        	 		a[i][j]=a[i][k]+a[k][j]; 
	print(a,v); 
}
bool control(int **a,int v){
	int i,j;
	for(i=0;i<v;i++){
		if(a[i][i]!=0)
			return false;
		for(j=0;j<v;j++)
			if(a[i][j]!=a[j][i])
				return false;
	}
	return true;
}