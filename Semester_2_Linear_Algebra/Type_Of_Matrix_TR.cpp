#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3 
// 0 hicbir şey 1 herşey 2 kosegen 3 skaler kosegen
int kosegen_kontrol(int x[N][N]);
int skaler_kontrol(int x[N][N]);
int birim_kontrol(int x[N][N]);
main(){
	int i,j;
	int a[N][N];
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			printf("a[%d][%d]",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	switch(kosegen_kontrol(a)){
		case 0: printf("kosegen degil"); break;
		case 1:	printf("kosegen,skaler ve birim matristir."); break;
		case 2: printf("sadece kosegendir"); break;
		case 3: printf("skaler kosegendir"); 
	}
	
}
int kosegen_kontrol(int x[N][N]){
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(i!=j&&x[i][j]!=0)
				return 0;
	return skaler_kontrol(x);
}
int skaler_kontrol(int x[N][N]){
	int i,j;
	for(i=0;i<N;i++)
		if(x[i][i]!=x[0][0])
			return 2;
	return birim_kontrol(x);
}
int birim_kontrol(int x[N][N]){
	int i,j;
	for(i=0;i<N;i++)
		if(x[i][i]!=1)
			return 3;
	return 1;
}