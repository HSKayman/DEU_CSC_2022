#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	unsigned int i=-1,j,size=10;
	double *x=(double *)malloc(size*sizeof(double)),*y=(double *)malloc(size*sizeof(double));
	printf("\nLutfen X i yazma sirasinda Esc'ye basincaya Kadar Giris Yapiniz.\n");
	while(1){
		printf("(x,y) :");
		char a[10],b[10];
		scanf("%s",a);
		if(a[0]==27)
			break;
		if(i+1>=size){
			size*=size;
			x=(double *)realloc(x,size*sizeof(double));
			y=(double *)realloc(x,size*sizeof(double));
		}
		scanf("%s",b);
		x[++i]=atof(a);
		y[i]=atof(b);
	}
	unsigned int count=i+1;
	char a;
	do{
		double result=0;
		double xi;
		printf("\nHangi X'i Bulacaksiniz :");
		scanf("%lf",&xi);
		for(i=0;i<count;++i){
			double temp=y[i];
			for(j=0;j<count;++j)  
			  if(i!=j) 
			    temp*=(xi-x[j])/(x[i]-x[j]);
			result+=temp;
		}
		printf("%lf\n",result);
		printf("\nBirdaha Yapmak Ister Misiniz ?[E/H]:");
		getchar();
		scanf("%c",&a);
	}while(a=='E'||a=='e');
}