#include<stdio.h>
#include<math.h>
int main(){
	char a[300]; printf("Lutfen Sayilari aralarinda virgul birakarak giriniz:"); scanf("%s",a);
	int i,say=0,j,sum=0,count=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!=','&&a[i+1]!='\0')
		{
			say++;
		}
		else if(a[i+1]!='\0')
		{
			
			count++;
			for(j=(i-say);j<i;j++)
			{	
				sum+=int(a[j]-48)*(int)pow(10,--say);
			}	
		}else{
			count++;
			for(j=i-say;j<=i;j++)
			{	
				sum+=int(a[j]-48)*(int)pow(10,say--);
			}
		}
	}
printf("Dizideki Sayilarin Sayisi:%d\nDizideki Sayilarin Toplami:%d",count,sum);
}
