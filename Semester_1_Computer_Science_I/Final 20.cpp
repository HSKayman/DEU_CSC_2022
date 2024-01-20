#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[4][4],i,j,u,n,m,s;
	srand(time(0));
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j]=rand()%101;	
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
	int max=a[0][0],min=a[0][0];
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(max<a[i][j])
			{
				max=a[i][j];
				u=i;
				n=j;
			}
			if(min>a[i][j])
			{
				min=a[i][j];
				m=i;
				s=j;
			}
		}
	}
	int swp=a[u][n];
	a[u][n]=a[m][s];
	a[m][s]=swp;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}



}
