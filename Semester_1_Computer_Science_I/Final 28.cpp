#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define AS 21
main(){
	int j,i,a[AS];
	srand(time(0));
	for(i=0;i<AS;i++)
	{
		a[i]=rand()%101;
	}	
	for(i=0;i<AS-1;i++)
	{
		for(j=i+1;j<AS;j++)
		{
			if(a[i]>a[j])
			{
				int swp=a[i];
				a[i]=a[j];
				a[j]=swp;		
			}

		}
	}
	
	for(i=0;i<AS;i++)
		printf("%d\n",a[i]);
	printf("\n\n--------------------------------------\n\n");
	for(i=0;i<AS-1;i++)
	{
		if(a[i+1]!=a[i]&&a[i+1]!=a[i]+1)
		{
		a[i]=rand()%(a[i+1]-a[i])+a[i];
		}
		else
			continue;
	}
	
	for(i=0;i<AS-1;i++)
		printf("%d\n",a[i]);
	
	
	
}

