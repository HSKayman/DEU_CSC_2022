#include<stdio.h>
int main(){
	int a[10]={0},i;
	float sum=0;
	for(i=0;i<10;i++){
		printf("Lutfen %d. Degeri Giriniz :",i+1);
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int b[9]={0},f=0;
	sum/=10.00;
	for(i=0;i<10;i++){
		if(sum>a[i]){
			b[f++]=a[i];
		}
	}
}