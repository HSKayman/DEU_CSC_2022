#include<stdio.h>
void H(int a,char b,char d,char c);
int count=1;
	int main(){
		int a;
		char b,d,c;
		printf("Lutfen Hanoi Of Tower Sayisini Giriniz:"); scanf("%d",&a);
		H(a,'A','C','B');
	}
void H(int x,char a,char c,char b)
{
	if(x==1)
	{
		printf("\n%d %c--->%c\n",count++,a,c);
	}
	else
	{
		H(x-1,a,b,c);
		printf("\n%d %c--->%c\n",count++,a,c);
		H(x-1,b,c,a);
	}
	return;		
}
