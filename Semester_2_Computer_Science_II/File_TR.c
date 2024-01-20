#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	int i;
	FILE *p;
	p=fopen("Stroge.txt","w+");
	while(1){
		printf("cikmak icin noya -1 giriniz e basiniz.\n");	
		printf("numaran  :"); scanf("%d",&i);
		if(i==-1)
			break;
		printf("\nisim :"); char a[200];getchar();scanf("%[^\n]s",a);
		fprintf(p,"%s %s\n",a,i);
	}
	rewind(p);
	char a[3000];
	fscanf(p,"%[^\0]s",a);
	printf("%s",a);
	fclose(p);
}