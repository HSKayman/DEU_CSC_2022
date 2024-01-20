#include<stdio.h>
int main(){
	char a[1000];
	scanf("%[^\n]s",a);
	getchar();
	char b;
	scanf("%c",&b);
	int i,count=0;
	for(i=0;a[i];i++)
		if(a[i]==b)
			count++;
	printf("%d",count);
}