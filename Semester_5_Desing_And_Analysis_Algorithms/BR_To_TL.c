#include<stdio.h>
int fucn(int,int);
int main(){
	int i,j;
	for(i=2;i<6;++i)
		for(j=2;j<6;++j)
			printf("%d for (%d,%d)\n",fucn(i,j),i,j);
}
int fucn(int x,int y){
	if(x==1||y==1)
		return 1;
	return fucn(x-1,y)+fucn(x,y-1);
	// caprazlari dahil etmek istersen +func(x-1,y-1)
}
