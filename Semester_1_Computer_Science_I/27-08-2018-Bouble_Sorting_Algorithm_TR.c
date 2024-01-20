#include<stdio.h>
int main(){
	int a[]={5,7,2,9,6,1,3,7};
	for(int i=0;i<7;i++){
		for(int j=0;j<8-i;j++){
			if(a[j]<a[j+1]){
				int g=a[j+1];
				a[j+1]=a[j];
				a[j]=g;
			
			}
				for(int i=0;i<8;i++){
		printf("%d\n",a[i]); 
		}printf("\n\n");
		
	}

	}
}
