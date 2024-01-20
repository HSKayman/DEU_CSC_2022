#include<stdio.h>
#include<math.h>
int main()
{
	printf("Lutfen sayin Giriniz. "); int a; scanf("%d",&a);
	int geca=a,i=0,as[50];
	while(geca!=0)
	{
		geca/=10;
		i++;
	}
	int j,yer=0;
	geca=a;
	for(j=i-1;j>-1;j--)
	{
	
		as[yer++]=geca/pow(10,j);
		geca-=pow(10,j)*as[yer-1];
	}
	int sum=0;
	for(j=0;j<yer;j++)
		sum+=as[j];
	
	int f =as[yer-1];
	as[yer-1]=as[0];
	as[0]=f;
	int sum2=0,sayf=0;;
	for(j=yer-1;j>-1;j--)
	sum2+=pow(10,j)*as[sayf++];
	printf("Sayinin rakamlari Toplami =%d\n\n\nSayinin basi ile sonunun yer degistirmis hali %d\n",sum,sum2);

}
