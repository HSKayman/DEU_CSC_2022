#include<stdio.h>
int main(){
	int i,j,a;
	printf("Lutfen Sayi Giriniz :");
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		for(j=1;j<=a;j++)
			printf("%d x %d = %d\t",i,j,i*j);
	printf("\n");
	}		
}