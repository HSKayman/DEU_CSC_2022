#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Q 4
int main(){
	int i,j,c[Q][Q],a[Q][Q],b[Q][Q];
	srand(time(0));
	for(i=0;i<Q;i++)
		for(j=0;j<Q;j++){
			a[i][j]=rand()%100;
			b[i][j]=rand()%100;
		}
	for(i=0;i<Q;i++)
		for(j=0;j<Q;j++)
			c[j][i]=3*b[j][i]-2*b[i][j];					
	for(i=0;i<Q;i++){
		for(j=0;j<Q;j++)
			printf("%5d",c[i][j]);
		printf("\n");
	}
	float r=-1,i,j,a[40][40],b[40][40],c[40][40];	
	/*srand(time(0));
	for(i=0;i<40;i++)
		for(j=0;j<40;j++){
			a[i][j]=rand()%100;
			b[i][j]=rand()%100;
		}
	for(i=0;i<40;i++)
		for(j=0;j<40;j++)
			b[i][j]*=r;
	for(i=0;i<40;i++)
		for(j=0;j<40;j++)
			c[i][j]=a[i][j]+b[i][j];
	for(i=0;i<40;i++){
		for(j=0;j<40;j++)
			printf("%5.2f",c[i][j]);
		printf("\n");
	}
}*/
}