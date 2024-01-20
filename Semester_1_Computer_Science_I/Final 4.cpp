#include<stdio.h>
#include<math.h>
int main()
{
	printf("Lutfen Bir Sayi Giriniz."); int n; scanf("%d",&n);
	int i,j,essek;
	double allah;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			essek=i*i+j*j;
			allah=sqrt(essek);
			if(essek<=n*n&&allah-(int)(allah)==0)
			{
				printf("%d  %d   %.0lf\n",i,j,allah);
			}
		}
	}
}
