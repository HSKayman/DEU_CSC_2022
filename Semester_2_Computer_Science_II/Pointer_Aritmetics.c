#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>
int f(int *i){
	(*i)++;
	(i)++;
	(*i)++;
	(i)++;
	(*i)++;
}
int main(){
	int a[3]={5,6,7};
	printf("\n%d %d %d",a[0],a[1],a[2]);
	f(a);
	printf("\n%d %d %d\n",a[0],a[1],a[2]);
}