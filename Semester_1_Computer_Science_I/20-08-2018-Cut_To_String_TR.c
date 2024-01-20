#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *f(char *x,int y){
	
	if(y>strlen(x))
	return NULL;
	else
	return (x+y);
}

int main(){
	char dizi[15];
	scanf("%s",dizi);
	printf("En bastan ilk kac hark kirpilsin ?"); int a; scanf("%d",&a);
	printf("%s",f(dizi,a));
	

} 