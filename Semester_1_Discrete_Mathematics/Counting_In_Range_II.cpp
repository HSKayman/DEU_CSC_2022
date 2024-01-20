#include<stdio.h>
#define F 7
int main(){int n=0;
	for(int i=1;i<=F-2;i++){
		for(int j=i+1;j<=F-1;j++){
			for(int k=j+1;k<=F;k++){
				n+=1;
			}
		}
	}
	printf("%d",n);
}
