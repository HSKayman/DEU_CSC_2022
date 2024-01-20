#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int b=1;
	int c=1;
	int d= b+c;
	printf("%d\n%d\n",b,c);
	for(int i=0;i<a-2;i++){
		d=b+c;	
		printf("%d\n",d);
		c=b;
		b=d;
		
		
	}
}