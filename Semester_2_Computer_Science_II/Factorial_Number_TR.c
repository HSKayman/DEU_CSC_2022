#include<sdtio.h>
int main(){
	unsigned long long a,sum=1;
	printf("Lutfen sayi giriniz :");
	scanf("%llu",&a);
	int i;
	if(a<=1)
		sum=1;
	for(i=2;i<=a;i++)
		sum*=i;
		
	printf("\n%llu",sum);
}