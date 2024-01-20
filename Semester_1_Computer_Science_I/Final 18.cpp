#include<stdio.h>
int main()
{
	printf("Lutfen Cumle Giriniz:"); char a[300]; scanf("%[^\n]s",a);
	getchar();
	printf("Lutfen Bir Cumle Daha Giriniz:"); char b[300]; scanf("%[^\n]s",b);
	int i,j,f;
	for(i=0;a[i]!=0;i++)
	{
		f=0;
		for(j=0;b[j]!=0;j++)
		{
			if(a[i]==b[j])
			{
				f=1;
				break;
			}
			
		}
		if(f!=1)
		{
			printf("\n\nTum karakterler birbirlerinde yoktur.");
			break;
		}
	}
	if(f==1){
		printf("\n\nTum karakterler birbirlerinde vardir.");
	}
	
}
