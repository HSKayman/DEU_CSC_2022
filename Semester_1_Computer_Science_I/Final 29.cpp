#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define AS 75
#define KAS 5
main(){
	int j,i,a[AS],b[KAS];
	srand(time(0));
	for(i=0;i<AS;i++)
		a[i]=rand()%101;
	for(i=0;i<KAS;i++)
		b[i]=rand()%101;
	int f;
	for(i=0;i<AS;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("\n\n-----------\n\n");
		for(i=0;i<KAS;i++)
	{
		printf("%d\n",b[i]);
	}
	for(i=0;i<KAS;i++)
	{
		f=0;
		for(j=0;j<AS;j++)
		{
			if(a[j]==b[i])
			{
				f=1;
			}	
		}
	if(f==0)
	{
		printf("Icermez");
		break;
	}
	}
	if(i==KAS)
	{
		printf("Icerir.");
	}
	
	
	
	
	
	
}
