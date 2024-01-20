#include<stdio.h>
int main()
{
	printf("Lutfen dikdortgen tuglanin a,b,c sinin boyutunu giriniz.::>"); int a[3],x,y,i,j,f=1; scanf("%d%d%d",&a[0],&a[1],&a[2]);
	printf("Lutfen Deligin x,y sini giriniz.::>"); scanf("%d%d",&x,&y);
	x*=y;
	for(i=0;i<2;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(a[i]*a[j]>=x)
				f=0;
		}
	}
	if(f==0)
		printf("Delikten Gecer.");
	else
		printf("Delikten Gecmez.");


}
