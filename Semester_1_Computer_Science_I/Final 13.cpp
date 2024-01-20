#include<stdio.h>
#include<math.h>
int main()
{
	printf("Lutfen sayin Giriniz. "); char a[30]; scanf("%s",a);
	int i,sum=0;
	for(i=0;i<29;i++)
	{
		if(a[i]!='\0')
		{
			sum+=a[i]-'0';
		}
		else 
			break;
	}
	printf("Sayinin rakamlari Toplami =%d\n\n\nRakam Sayisi:%d\n",sum,i);

}
