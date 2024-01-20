#include<stdio.h>
void shell_sort (int *p,int size){
	int i,j,k,l;
	for(k=size;k>1;){
		k=(k<5) ? 1: ((k*5-1)/11);
			for(i=k-1;++i<size;){
				l=p[i];
					for(j=i;p[j-k]>l;){
						p[j]=p[j-k];
							if((j-=k)<k)
								break;
					}
				p[j]=l;
			}
	}
}
int main(){
	int a[]={1,8,7,6,5,4,3,2,12,34,45,656,67};
	int b= sizeof(a)/sizeof(int);
	shell_sort(&a[0],b);
	for(int i=0;i<b;i++){
		printf("%d\n",a[i]);
	}
} 
