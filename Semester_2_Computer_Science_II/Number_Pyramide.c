#include<stdio.h>
int main(){
	int i,j;
	int a;
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		for(j=1;j<=i;j++)
			printf("%3d",j);
		printf("\n");
	}
	printf("\n---------------------------------\n\n\n\n\n");
	for(i=1;i<=a;i++){
		for(j=1;j<=i;j++)
			printf("%3d",i);
		printf("\n");
	}
}