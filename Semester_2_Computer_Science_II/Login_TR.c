#include<stdio.h>
#include<string.h>
int main(){
	char a[1000];
	int i=1;
	do
	{
		if(i<4){
			printf("yanlis\n\n");
			i++;
		}
		else if(i==4){
			printf("hakkiniz doldu\n\n");
			break;
		}
		getchar();
		scanf("%[^\n]s",a);
	}while(0!=strcmp("math",a));
		if(i<4)
			printf("sifre dogru");
	



}