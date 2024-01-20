#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[33]={0},i=0;
	srand(time(0));
	for(i=0;i<31;i++)
	{
		a[i]=rand()%2;
	}
	int ctrl=a[0],deg=0;
	for(i=0;i<31;i++)
	{
		if(ctrl!=a[i])
		{
			deg++;
			ctrl=a[i];
		}
	}
printf("Donusum Sayisi ====>%d",deg);
}

