#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[4][4],i,j,u;
	srand(time(0));
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j]=rand()%141+40;	
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------\n\n");
	int max=a[0][0],sum2;
	for(i=0;i<4;i++)
	{
		sum2=0;
		for(j=0;j<4;j++)
		{
			sum2+=a[i][j];
		}
		if(max>sum2)
			{
				max=sum2;
				u=i;
			}
	}
	printf("%d. Satir==>",u+1);
	for(i=0;i<4;i++)
	{
		printf("%4d",a[u][i]);
	}
	printf("=%d",max);
}

