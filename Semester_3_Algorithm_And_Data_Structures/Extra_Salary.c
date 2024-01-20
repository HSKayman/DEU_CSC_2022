#include<stdio.h>
#include<stdlib.h>
int main(){
	double x;
	scanf("%lf",&x);
	int i=0;
	double y=(double)4/(double)100;
	char a;
	do{
		printf("\n%d     %lf    %lf\n",++i,x+y*x,y);
		y+=0.04;
		scanf("%c",&a);
	}while(a!='1');
}