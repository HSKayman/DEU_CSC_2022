#include<stdio.h>
int main(){
	int a[]={2,3,9,8,15};
	int i,j;
	int l=0,g;
		while(l<5){
			printf("%d\t",a[l]);
			l++;
		}
		for(j=0;j<2;j++){
			g=a[j];
			a[j]=a[4-j];
			a[4- j]=g;
		}
		
		
		printf("\n");
		int k=0;
		while(k<5){
			printf("%d\t",a[k]);
			k++;
		}
		
	} 