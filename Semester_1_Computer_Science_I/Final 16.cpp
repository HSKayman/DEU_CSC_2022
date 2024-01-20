#include<stdio.h>
int main()
{
	int i,j,count=0,start,end,max=300;
	printf("Lutfen Cumle Giriniz(Sonunda Nokta olmali):"); char a[300]; scanf("%[^\n]s",a);
	for(i=0;a[i]!=46;i++)
	{
		if(a[i]!=32&&a[i+1]!='.')
		{
			count++;
		}
		else if(max>count)
		{
			start=i-count;
			end=i;
			max=count;
			count=0;
			if(a[i+1]=='.')
				max++;
		}else{
			count=0;
		}
	}
	printf("Cumlenizdeki En Uzun Kelime :::>");
	for(i=start;i<=end;i++)
		printf("%c",a[i]);	
}
