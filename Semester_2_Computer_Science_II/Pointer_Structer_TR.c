#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int no;
	char ad[20];
	int not;
}Ogr;

int main(){
	Ogr *a;
	int s=10;
	a=(Ogr *)malloc(s*sizeof(Ogr));
	int i,count=0;
	for(i=0;;i++){
		printf("\nLutfen Ogrencinin nosunu giriniz: ");
		int n;
		scanf("%d",&n);
		if(n==-1){
			printf("\ngiris islemi tamamlanmistir.");
			break;
		}
		a[i].no=n;
		printf("\n Lutfen Ogrenicin Adini giriniz: ");
		char ad1[20];
		scanf("%s",ad1);
		strcpy(a[i].ad,ad1);
		printf("\n Lutfen Ogrencinin Notunu giriniz: ");
		scanf("%d",&a[i].not);
		if((i+1)%10==0){
			s+=10;
			a=(Ogr *)realloc(a,s*sizeof(Ogr));
			if(a=0)
				printf("sabit diskte yeterli yer yok\n\n\n");		
		}	
		count++;
	}
	for(i=0;i<count;i++){
		printf("%d %s %d\n",a[i].no,a[i].ad,a[i].not);
	}
}