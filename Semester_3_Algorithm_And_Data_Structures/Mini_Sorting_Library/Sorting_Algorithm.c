#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void Swap(int *x,int *y){
	if(x==y)
		return; 
	*x=*x+*y;   
	*y=*x-*y;   
	*x=*x-*y;   
}
void SelectionSort(int* x,int n){
	int i,j,min;
	for(i=0;i<n-1;++i){
		min=i;
		for(j=i+1;j<n;++j){
			if(x[min]>x[j]){
				min=j;
			}
		}
		Swap(&x[min],&x[i]);
	}
}
void BoubleSort(int*x,int n){
	int i,j;
	for(i=0;i<n-1;++i){
		bool f=true;
		for(j=0;j<n-i;++j){
			if(x[j]>x[j+1]){
				Swap(&x[j+1],&x[j]);
				f=false;
			}
		}
		if(f){
			return;
		}
	}
}
void QuickSort(int*x,int n);
void CountingSort(int*x,int n){
	int i,max=x[0],min=x[0];
	for(i=0;i<n;++i){
		if(max<x[i])
			max=x[i];
		if(min>x[i])
			min=x[i];
	}
	int j, *a=(int *)calloc((max-min)+1,sizeof(int));
	for(i=0;i<n;++i)
		++a[x[i]-min];
	int c=0;
	for(i=0;i<n;++c){
		for(j=0;j<a[c];++j){
			x[i++]=c+min;
		}
	}
}
void InsertSort(int*x,int n){
	int i,j,temp,temp2,temp3;
	for(i=1;i<n;++i){
		temp=i;
		temp3=x[i];
		temp2=-9;
		for(j=i-1;j>-1;--j){
			if(x[i]<x[j]){
				temp2=j;
			}
		}
		if(temp2!=-9){
			for(j=temp;j>temp2;--j){
				x[j]=x[j-1];
			}
			x[temp2]=temp3;
		}
	}
}
void Print(int *x,int n){
	int i;
	for(i=0;i<n;++i){
		printf("%d\t",x[i]);
	}
	printf("\n");
}
int main(){
	int a[]={1,4,5,8,2,3,8,0,5,2,12};
	int n=sizeof(a)/sizeof(a[0]);
	Print(a,n);
	InsertSort(a,n);
	Print(a,n);
}	