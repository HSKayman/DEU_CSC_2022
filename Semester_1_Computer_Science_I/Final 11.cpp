#include<stdio.h>
int main()
{
	char a[4],b[4];printf("Lutfen santranc tahtasi rotalari girin===>"); scanf("%s %s",a,b);//a=97
	a[3]='\0';
	b[3]='\0';
	int i,j;
	int flag,flag2;
	for(i=49;i<=56;i++)
	{
		for(j=97;j<105;j++)
		{
			if(a[0]==j&&a[2]==i)
			{
				if((i%2==1&&j%2==1)||(i%2==0&&j%2==0))
				{
					printf("\nIlk Girdiginiz Kare Siyah Renklidir."); flag=1;
				}else{
				
					printf("\nIlk Girdiginiz Kare Beyazdir."); flag=2;
				}
			}
			if(b[0]==j&&b[2]==i)
			{	
				if((i%2==1&&j%2==1)||(i%2==0&&j%2==0))
				{
					printf("\nSon Girdiginiz Kare Siyah Renklidir."); flag2=1;
				}else{
				
					printf("\nSon Girdiginiz Kare Beyazdir."); flag2=2;
				}
			}
			
		}
	}
	if(flag==flag2){
		printf("\n\n\nIki karede ayni renklidir.");
	}else
			printf("\n\n\nIki karede ayni renkli degildir.");
}
