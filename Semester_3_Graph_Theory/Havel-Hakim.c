#include<stdio.h>
#include<stdlib.h>
void sorting(int *,int);
int control(int *,int);
int main(){
	int vc=4,i=0;
	int *a=(int *)malloc(vc*sizeof(int));
	printf("\nLutfen Tepe Dereceleri Girmeye Baslayiniz..\n");
	do{
		printf("\nCikmak Icin Negatif Sayi Giriniz :");
		int b;
		scanf("%d",&b);
		if(b<0)
			break;
		if(i+1>=vc){
			vc*=2;
			a=(int *)realloc(a,vc*sizeof(int));
		}
		a[i++]=b;
	}while(1);
	printf("\nBu Dizi Graf %s",control(a,i) ? "Dizisidir.":"Dizisi Degildir");
}

void sorting(int *a,int v){
	int i,j;
	for(i=0;i<v-1;i++)
		for(j=i+1;j<v;j++)
			if(a[j]>a[i]){
				int swap=a[i];
				a[i]=a[j];
				a[j]=swap;
			}
}

int control(int *a,int v){
	int i,j,sum;
	for(i=0;i<v;i++){
		sum+=a[i];
		if(a[i]>=v)
			return 0;
	}
	if(sum%2==1)
		return 0;
	for(i=0;i<v;i++){
		sorting(&a[i],v-i);
		for(j=0;j<a[i];j++){
			if(j+i+1>=v)
				return 0;
			a[j+i+1]-=1;
			if(a[j+i+1]<0)
				return 0;
		}
	}
	return 1;
}