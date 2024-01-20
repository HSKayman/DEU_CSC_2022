#include<stdio.h>
#include<stdlib.h>
int main(){
	printf("\nSinifta Kac Arkadas Var: ");
	int p,i,j;
	scanf("%d",&p);
	int **a;
	a=(int **)malloc(p*sizeof(int *));
	for(i=0;i<p;i++){
		printf("%d id linin kac arkadasi vardir\n",i);
		int q;
		scanf("%d",&q);
		a[i]=(int *)malloc((q+1)*sizeof(int));		
		a[i][0]=q;
		for(j=1;j<q;j++){
			printf("\n%d idli Arkadasin %d. arkadasinin id sini Giriniz :\n",i,j);	
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<p;i++){
		printf("%d\t",i);
		for(j=1;j<a[i][0];j++)
			printf("%d  ",a[i][j]);
		printf("\n");
	}		
}