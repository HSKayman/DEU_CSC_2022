#include<stdio.h>
int fib(int x);
int main(){
	int i;
	for(i=1;i<19;i++)
		printf("%d\n",fib(i));

}
int fib(int x){
	static int a=1,b=1;
	int c=a+b;
	a=b;
	b=c;
	return c;
}