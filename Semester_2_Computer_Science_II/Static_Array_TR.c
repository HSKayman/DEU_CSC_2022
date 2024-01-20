#include<stdio.h>
#include<stdlib.h>
#define L 10
int main(){
	int *x,i,a,s=1;
	x=(int *)malloc(10*s*sizeof(int));
	for(i=1;1;i++){
		printf("\n-1 basana kadar %d. degere girebilirsiniz :",i);
		scanf("%d",&a);
		if(a==-1)
			break;
		else if(i%10==0){
			x=(int *)realloc(x,10*++s*sizeof(int));
			if(x==NULL){
				printf("\nYer Kalmadi");
				break;
			}
			*(x+i)=a;		
		}else
			*(x+i)=a;

	}
	for(a=1;a<i;a++)
		printf("%d ",*(x+a));
}