#include<stdio.h>
#include<string.h>
int main()
{
	int am[300]={0};
	printf("Lutfen Cumle Giriniz:"); char a[300]; scanf("%[^\n]s",a);
	getchar();
	printf("Lutfen Bir Cumle Daha Giriniz:"); char b[300]; scanf("%[^\n]s",b);
	int i,j,f,e=-1,asdas;
	for(i=0;a[i]!=0;i++)
	{
		f=0;
		for(j=0;b[j]!=0;j++)
		{
			if(a[i]==b[j])
			{
				f=1;
				am[j]=1;	
			}
		}
		if(f==1&&e==-1)
		{
			e=i;
		}
		if(e!=-1){
			if(f!=1){
				e=-1;
			for(asdas=0;asdas<300;asdas++)
				am[asdas]=0;
			}
		}
	}
	for(i=0;i<=strlen(b);i++){
		if(am[i]!=1){
			break;
		}
	}
	
	if(e!=-1&&f==1&&i==strlen(b)){
		printf("%d",e);
	}else
		printf("-1");
	
}
