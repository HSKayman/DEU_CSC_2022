#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ust(int x,int y){
	if(y==1){
		return x;
	}
	
	return x*ust(x,y-1);
}
int fac(int x){
	if(x==1){
		return 1;
	}
	return x*fac(x-1);
}
int fac1(int x){
	int f=1;
	for(int i=1;i<=x;i++){
		f*=i;
	}
	return f;
}
int main(){
	printf("Lutfen faktoriyelini almak istediginiz sayiyi giriniz :");
	int a; scanf("%d",&a);
	printf("\n Isleminizin sonucu : %d",fac(a));
	printf("\n Isleminizin sonucu : %d",fac1  (a));
	printf("%d",ust(5,3));
}
