#include<stdio.h>
void Sirala(int *);
int main(){
	int i;
	int *a;
	a=(int *)malloc(6*sizeof(int));
	srand(time(0));
	for(i=0;i<6;i++){
		*(a+i)=rand()%54+1;
		printf("\n%d",a[i]);
	}
	Sirala(a);
	printf("\n\n\n\n\n\n*******************************\n\n\n\n\n");
	for(i=0;i<6;i++)
		printf("\n%d  ",a[i]);
	free(a);

}
void Sirala(int *a){
	int i,j;
	for(i=0;i<6;i++){
		for(j=i+1;j<6;j++){
			if(a[j]>a[i]){
				int swap=a[j];
				a[j]=a[i];
				a[i]=swap;
			}
		}
	}
}