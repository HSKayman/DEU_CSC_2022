#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	int a[7][7]={0},i,j,s;
	srand(time(0));
	for(i=0;i<7;i++)
	{
		s=rand()%7;
		a[i][s]=1;
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
}
