#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	int i;
	char a[100];
	srand(time(0));
	for(i=0;i<rand()%100+1;i++)
		a[i]='A'+rand()%('Z'-'A');
	a[i]='\0';
	FILE *p;
	p=fopen("12.txt","w+");
	fprintf(p,"%s",a);
	rewind(p);
	fscanf(p,"%[^\0]s",a);
	printf("%s",a);
	fclose(p);
}