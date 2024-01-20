#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int benimfonk(char *a){
	int say=0;
	for(int i=0;*(a+i)!='\0';i++){
		say++;
	}
	return say;
}
int main(){
	int qw[99];
	int *p;
	p=&qw[1];
	for(int iq=0;iq<99;iq++){
		qw[iq]=iq;
	}
	for(int ie=-1;ie<98;ie++){
		printf("\n%p - %u - %d",(p+ie),(p+ie),*(p+ie));
	}
	char yazi[]="tura";
	char *pqq=&yazi[0];
	printf("%s",pqq+2);
	char a[30];
	scanf("%30s",&a);
	printf("%d <--- girdiginiz kelimenin uzunlugudir",benimfonk(a));

}