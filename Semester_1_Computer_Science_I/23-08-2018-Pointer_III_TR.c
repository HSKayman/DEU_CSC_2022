#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char isim=5;;
	char *ptr;
	ptr=&isim;
	printf("%d",*ptr);
	char *sehir="Osmaniye";
	while(*sehir!=NULL){
		printf("%c - %x \n",*(sehir),sehir);
		sehir++;
	}
	int *p;
	int f;
	for(int j=0;f!=-1;j++){
		if(f!=-1){
		
		printf("Lutfen %d. sayiyi giriniz.",j+1); scanf("%d",&f);
		p=&f;
	}}
	for(int i=0;p[i]!=NULL;i++){
		printf("%d - %p\n",*(p+i),(p+i));
	}
}