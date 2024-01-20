#include <stdio.h>
int main(){
	int a[10];
	int i;
	for(i=0; i<10; i++){
		a[i]=i;
		printf("%d\n",a[i]);
	}
int n=0;
	int c[20];
	for(i=2; n<20;i++){
		int j,f=1;
		for(j=2;j<i;j++){
		if(i%j==0)
			f=0	;
		}
	if(f==1){
	c[n]=i;
	n++;
}
	
	}
	int k;
	k=1;
	while(k<20){
		printf("%d\n",a[k]);
		k++;
	}
}