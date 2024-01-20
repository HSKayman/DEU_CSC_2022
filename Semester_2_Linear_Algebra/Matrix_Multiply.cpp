#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3
#define M 2
#define T 3
int main(){
	int a[N][M]={{-2,5},{4,-3},{2,1}},b[M][T]={{1,2,-1},{3,1,4}},i,j,k,c[N][T]={0};
	for(i=0;i<N;i++){
		for(j=0;j<T;j++){
			int sum=0;
			for(k=0;k<M;k++){
				sum+=a[i][k]*b[k][j];
			}
			c[i][j]=sum;
		}	
	}
	for(i=0;i<N;i++){
		for(j=0;j<T;j++)
			printf("%10d",c[i][j]);
		printf("\n");
	}
}