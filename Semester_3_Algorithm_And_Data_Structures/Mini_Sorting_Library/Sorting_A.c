#include<stdio.h>
#include<stdlib.h>
#include"Sorting_Algorithm.h"
int main(){
	int a[]={1,4,5,8,2,3,8,0,5,2,12};
	int n=sizeof(a)/sizeof(a[0]);
	Print(a,n);
	BoubleSort(a,n);
	Print(a,n);
}