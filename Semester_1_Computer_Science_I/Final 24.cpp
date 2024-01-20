#include<stdio.h>
 int main(){
	q2:int i,j,b,q;
	printf("N:"); scanf("%d",&b);
	int s=b*b;
	printf("\n\n");
	int a[b+1][b+1]={0};
	for(q=0;q<=b/2;q++)
	{
		
		for(j=q;j<b-q;j++)
		{		
			a[q][j]=s;
			s--;
		}
		for (i=1+q;i<b-q;i++){
			a[i][b-1-q]=s;
			s--;
		}
		for (j=b-1-q;j>0+q;j--){
			a[b-1-q][j-1]=s;
			s--;
		}	
		for (i=b-2-q;i>=1+q;i--){
			a[i][q]=s;
			s--;
		}
	}  	
	for (i=0;i<b;i++){
		for(j=0;j<b;j++){
			printf("%d\t",a[i][j]);
		}
	printf("\n");
	}
}

