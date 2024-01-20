#include<stdio.h>
unsigned long long pow(int x,int y);
int main(){
	printf("%llu",pow(5,3));
}
unsigned long long pow(int x,int y){
	if(y==1)
		return x;
	else
		return x*as(x,y-1);
}