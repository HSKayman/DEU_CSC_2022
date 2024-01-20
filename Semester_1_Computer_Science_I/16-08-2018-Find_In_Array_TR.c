#include<stdio.h>
int main(){
	int q[10],a,f=0,i;
	for(int i=0;i<10;i++){
		printf("Lutfen Sayi giriniz :"); scanf("%d",&q[i]);
	}
	system("CLS");	 
	printf("Lutfen aramak istediginiz sayiyi giriniz."); scanf("%d",&a);
	for(i=0;i<10;i++){
		if(a==q[i]){
		f=1; break;}
	}
	
if(f==1){
	printf("girdiginiz sayi bulundu. %d sayisi dizinin %d. indisinde var",a,i);
	
	}
else
printf("girdiginiz sayi bulunamadi.");
}