#include<stdio.h>
int saltanat(int x);
int main()
{
	printf("Lutfen Sayi Giriniz."); int n; scanf("%d",&n);
	int i,h;
	for(i=1;i<=n;i++)
	{
		if(saltanat(i)==1)
		{
			if(saltanat(2*i-1)==1&&2*i-1<=n)
			{			
				printf("%d Mersen Bir Sayidir\n",2*i-1);					
			}
		}
	}
}

int saltanat(int x)
{
	if(x<=1)
	{
		return 0;
	}
	int i;
	for(i=2;i<x;i++)
	{
		if(x%i==0)
		{
			return 0;
		}
	}
	return 1;
}
