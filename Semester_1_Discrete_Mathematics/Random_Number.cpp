#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int topla(int x,int y);
void selamver(char a[]);
int toplam(int x[]);
void doldur(int aa[],int sa[],int da);
int main(){
	
	int c;
	c=topla(66, 12);
	char a[11];
	printf("\n lutfen isminizi yaziniz.\n"); scanf("%s",a);
	printf("%d",c);
	selamver(a);
	int aa[]={12,23,34,45,56,67,78,89,-1};
	printf("\n%d\n",toplam(aa));
	int as[3],sa[3];
	doldur(as,sa,3);
}
int topla(int x,int y){
	int z=x+y;
	return z;
}int toplam(int x[]){
	int z=0;
	int i=0;
	while(x[i]!=-1){
	i++; z=z+x[i];}
	return z;
}
void selamver(char a[]){
	printf("\nMerhaba %s...\n",a);
}
void doldur(int as[],int sa[],int c){
	srand(time(0));
	for(int i=0;i<c;i++){
		as[i]=rand()%100;
		sa[i]=rand()%100;
		printf("%d\t%d\n",as[i],sa[i]);
	}
}

