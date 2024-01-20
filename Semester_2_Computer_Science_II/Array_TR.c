#include<stdio.h>
#include<stdlib.h>
int main(){
	int s,*dizi,k=0;
	FILE *f;
	if((f=fopen("sayilar.bin","wb+"))==NULL){
		printf("Dosya Acilamadi!\n");
		return 0;
	}
	do{
		scanf("%u",&s);
		if(s<0){
			printf("Negatif sayi girme\n");
			continue;
		}
	if(s==0)
	       	break;
	fwrite(&s,sizeof(unsigned int),1,f);
	k++;
	}while(1);
	fseek(f,0,SEEK_SET);
	dizi=(int *)malloc(sizeof(int)*k);
	fread(dizi,sizeof(int),k,f);
	for(s=0;s<k;s++)
		printf("%u\n",*(dizi+s));
	fclose(f);
	return 0;

}