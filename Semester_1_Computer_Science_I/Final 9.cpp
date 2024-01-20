#include<stdio.h>
int main()
{
	printf("Gece Yarisindan Kac Saniye Gecti ==");int a;scanf("%d",&a);
	int a1=a-(3600*(a/3600));
	int a2=a1-(60*(a1/60));
	printf("Suan Saat %d:%d;%d",a/3600,a1/60,a2);
}
