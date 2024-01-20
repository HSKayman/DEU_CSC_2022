#include<stdio.h>
int fibb(int x);
int main(){
	int i;
	for(i=1;i<10;i++){
	printf("%d\n",fibb(i));
	}
}
int fibb(int x){
	if(x<=2)
		return 1;
	return fibb(x-1)+fibb(x-2);
}