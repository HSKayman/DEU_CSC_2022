#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define AS 4000
main(){
	int i,a[AS];
	srand(time(0));
	for(i=0;i<AS-1;i++)
	{
		a[i]=rand()%101;
	}
	printf("Rastgele olusturulan sayilarin icinde hangi sayi var kontrol edeyim.::>"); int b,j; 
	scanf("%d",&b);
	for(i=0;i<AS-2;i++)
	{
		for(j=i+1;j<AS-1;j++)
		{
			if(a[i]>a[j])
			{
				int swp=a[i];
				a[i]=a[j];
				a[j]=swp;
			}
		}
	}int f=0;
	for(i=0;i<AS-1;i++)
	{
		if(a[i]==b){
			f=1;
		}
		else if(a[i]>b)
		{
			break;
		}
	}
	if(f==1){
		printf("Var");
	}else
		printf("Yok");
}
