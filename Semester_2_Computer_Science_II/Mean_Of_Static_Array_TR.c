#include<stdio.h>
#include<stdlib.h>
int main(){
	int *x,i,sum=0,N;
	printf("\nLutfen Eleman Sayisini Giriniz:");
	scanf("%d",&N);
	x=(int *)malloc(N*sizeof(int));
	for(i=0;i<N;i++){
	printf("\n%d. Elemani Giriniz : ",i+1);
	scanf("%d",&x[i]);
	sum+=x[i];
	}
	free(x);
	float ave=(float)sum/(float)N;
	printf("Ortalamasi %.2f",ave);
}