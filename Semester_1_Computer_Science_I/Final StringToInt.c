#include<stdio.h>
int main(){
	char a[102]; scanf("%[^\n]s",a);
	int i,count=0,sum=0;
	for(i=0;a[i]!=0;i++){
		if(a[i]>='0'&&a[i]<='9')
		{
			count++;
			sum+=a[i]-'0';
		}
	}
	printf("%d %d",count,sum);
}
