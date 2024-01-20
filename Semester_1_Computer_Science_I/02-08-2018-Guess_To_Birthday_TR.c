#include<stdio.h>
int main (){
	int k;
	printf("Lutfen bugunun tarihini giriniz:");
	scanf("%d",&k);
	printf("lutfen simdi de yasinizi giriniz:");
	int f;
	scanf("%d",&f);
	printf("Dogdugunuz tarih: %d \n dogru mu?",k-f);
}
