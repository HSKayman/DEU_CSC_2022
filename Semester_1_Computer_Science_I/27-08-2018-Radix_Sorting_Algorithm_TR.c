#include<stdio.h>
#include<stdlib.h>

int maks(int dizi[],int n){
	int max=dizi[0];
	for(int i=1;i<n;i++)
		if(dizi[i]>max)
			max=dizi[i];
	return max;
}

void sirala(int dizi[],int n,int exp){
	int disariver[n];
	int i,saydir[10]={0};
	
	for(i=0;i<n;i++)
		saydir[(dizi[i]/exp)%10]++;
		
	for(i=1;i<10;i++)
		saydir[i] += saydir[i-1];
		
	for(i=n-1;i>-1;i--){
		disariver[saydir[(dizi[i]/exp)%10]-1]=dizi[i];
		saydir[(dizi[i]/exp)%10]--;
	}
	
	for(i=0;i<n;i++)
		dizi[i]=disariver[i];
}
void radixsort(int dizi[],int n){
	int m=maks(dizi,n);
	for(int exp=1;m/exp>0;exp=exp*10)
		sirala(dizi, n, exp);
}

int main(){
	int dizi[50],say=0;
	for(int i=0;dizi[i-1]!=-1;i++){
	printf("Lutfen Siralanacak Sayilari Giriniz \nBitirmek icin -1'e basiniz\n:");scanf("%d",&dizi[i]);
	say++;
}
	int n=--say;
	radixsort(dizi, n);
	for(int i=0;i<n;i++)
		printf("%d ",dizi[i]);
	printf("\n\nAlgoritmamiz Radix Short Algoritmasidir.");
	return 0;
}
