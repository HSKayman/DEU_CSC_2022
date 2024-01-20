#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>
void sort(int *srt,int n);
void swap(int *x,int *y);
int difctrl(int y,int *x,int n);
int main(){
	int n=6;
	int a[n],i,j;
	srand(time(0));
	for(i=0;i<n;){
		int r=1+rand()%54;
		if(difctrl(r,a,i)){
			a[i]=r;
			printf("%d\n",a[i++]);
		}
	}
	sort(a,n);
	printf("\n------------\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);

}
int difctrl(int y,int *x,int n){
	int i;
	for(i=0;i<n;i++)
		if(*(x+i)==y)
			return 0;
	return 1;

}
void swap(int *x,int *y){
	int a=*x;
	*x=*y;
	*y=a;
}
void sort(int *srt,int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(*(srt+i)<*(srt+j))
				swap((srt+i),(srt+j));
}