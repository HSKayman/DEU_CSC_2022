#include<stdio.h>
int main()
{
	int a;
	do{
	printf("\nAdam Akilli 5in kati para giriniz.\n");	
	printf("Kac Para Cekeceksiniz ==>");  scanf("%d",&a);
	}while(a%5!=0);
	
	int a1=a-200*(a/200);
	int a2=a1-100*(a1/100);
	int a3=a2-50*(a2/50);
	int a4=a3-20*(a3/20);
	int a5=a4-10*(a4/10);
	printf("%d adet 200tl \n%d adet 100tl \n%d adet 50tl \n%d adet 20tl \n%d adet 10tl \n%d adet 5tl",a/200,a1/100,a2/50,a3/20,a4/10,a5/5);
}
