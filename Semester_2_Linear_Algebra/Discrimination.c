#include<stdio.h>
#include<stdlib.h>
float equ(float **,int);
int main(){
	int a,i,j;
	float **p;
	printf("\nLutfen Kare Matrisin Boyutunu Giriniz :");
	scanf("%d",&a);
	p=(float **)malloc(a*sizeof(float *));
	for(i=0;i<a;i++){
		p[i]=(float *)malloc(a*sizeof(float));
		for(j=0;j<a;j++){
			printf("\na[%d][%d] : ",i,j);
			scanf("%f",&p[i][j]);
		}
	}

	if(a==1)
		printf("\n Bu Matrisin Det. :%.2f",p[0][0]);
	else if(a==2)
		printf("\n Bu Matrisin Det. :%.2f",(p[0][0]*p[1][1]-p[0][1]*p[1][0]));
	else if(a==3)
		printf("\n Bu Matrisin Det. :%.2f",(p[0][2]*p[1][1]*p[2][0]+p[1][2]*p[2][1]*p[0][0]+p[2][2]*p[0][1]*p[1][0])-(p[0][0]*p[1][1]*p[2][2]+p[1][0]*p[2][1]*p[0][2]+p[2][0]*p[0][1]*p[1][2]));
	else
		printf("\n Bu Matrisin Det. :%.2f",equ(p,a));

	printf("\n");
}
int tringle(float **p,int a,int s,int e){
	int i;
	float q;
	if(p[e][e]!=0)
		q=p[s][e]/p[e][e];
	else
		return 1;
	for(i=0;i<a;i++)
		p[s][i]-=(q*p[e][i]);
	return 0;
}
float equ(float **p,int a){
	int i,j;
        for(j=0;j<a;j++)
     		for(i=j+1;i<a;i++)
			if(p[i][j]!=0)
				if(tringle(p,a,i,j))
 					return 0;
	float pi=1.0;
	for(i=0;i<a;i++)
		pi*=p[i][i];
	return pi;
}
