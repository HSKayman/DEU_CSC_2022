#include<stdio.h>
int main(){
	int a[]={5,7,2,9,6,1,3,7};
	for(int i=0;i<7;i++){
		for(int j=i+1;j<8;j++){
			if(a[j]>a[i]){
				int g=a[i];
				a[i]=a[j];
				a[j]=a[i+1];
				a[i+1]=g;
			
			}
				for(int i=0;i<8;i++){
		printf("%d\n",a[i]); 
		}printf("\n\n");
		
	}

	}
}
