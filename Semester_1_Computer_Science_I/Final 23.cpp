#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[20][2],i,j;
	srand(time(0));
	for(i=0;i<20;i++)
	{
		for(j=0;j<2;j++)
		{
			a[i][j]=rand()%101;	
		}
	}
	for(i=0;i<20;i++)
	{
		printf("X%d=%d     Y%d=%d\n",i+1,a[i][0],i+1,a[i][1]);
	}
	printf("\n\n\n");
	printf("Bulundugunuz Kordinati giriniz:"); int x,y; scanf("%d%d",&x,&y);
	int u[20][2];
	for(i=0;i<20;i++)
	{
		u[i][0]=(a[i][0]-x)*(a[i][0]-x)+(a[i][1]-y)*(a[i][1]-y);
		u[i][1]=i;	
	}
	for(i=0;i<20;i++)
	{
		for(j=i;j<20;j++)
		{
			if(u[i][0]>u[j][0])
			{
				int swp=u[j][0];
				u[j][0]=u[i][0];
				u[i][0]=swp;
				swp=u[j][1];
				u[j][1]=u[i][1];
				u[i][1]=swp;
			}
		}
	}
	printf("\n\n girdiginiz kordinatlara yakin en yakin uc nokta \nX1=%d Y1=%d\nX2=%d Y2=%d\nX3=%d Y3=%d\n",a[u[0][1]][0],a[u[0][1]][1],a[u[1][1]][0],a[u[1][1]][1],a[u[2][1]][0],a[u[2][1]][1]);
	
}

