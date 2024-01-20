#include<stdio.h>
int main(){
	int i,j,a[4][4]={0};
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%d. sutun %d. satir indisli degeri girin :",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(i<=j){
				printf("%4d",a[i][j]);
			}else
				printf("   ");
		}
		printf("\n");
	}
}