#include<stdio.h>
int com(int,int);
int fac(int);
int main(){
	int a;
	printf("Lutfen istediginiz pascal ucgeni satir sayisini giriniz :"); scanf("%d",&a);
	for(int i=0; i<=a;i++){
		for(int j=0;j<=i;j++){
			printf("%d \t",com(i,j));
		}
	printf("\n");
	}
	
	
}
int fac(int z){
 	int a=1,tc=1;
	 while(a<=z){
	 	tc*=a;
	 	a++;}
	return tc;
 }
int com(int x,int y){	
	return fac(x)/(fac(y)*fac(x-y));
}