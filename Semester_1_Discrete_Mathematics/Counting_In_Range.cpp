#include<stdio.h>
#define K 3
#define L 5
#define M 4
#define I 3
int main(){int say=0;
	for(int i=1;i<I;i++){
		if(i%K==0)	
			say++;
		else if(i%L==0)
			say++;
		else if(i%M==0)
			say++;
			
	}printf("%d",say);
}
