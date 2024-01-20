#include<stdio.h>
double mat1(int x,int y,int z);
double mat2(int x,int y,int z);
double mat3(int x,int y,int z);
int main(){
	printf("Lutfen 3 sayi giriniz : "); int a,b,c; scanf("%d%d%d",&a,&b,&c);
	double an;
	if(a<b&&b<c)
		an=mat1(a,b,c);
	else if(b<a&&a<c)
		an=mat2(a,b,c);
	else
		an=mat3(a,b,c);
	printf("%lf",an); 
}
double mat1(int x,int y,int z){
	return (double)((x+y)*z)/(double)(y+4);
}
double mat2(int x,int y,int z){
	return (double)((z-x)*y)/(double)(x+1);
}
double mat3(int x,int y,int z){
	return (double)(x+y+z)/(double)(2*y+z);
}