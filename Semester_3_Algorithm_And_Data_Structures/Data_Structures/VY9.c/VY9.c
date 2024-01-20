#include<stdio.h>
#include<stdlib.h>
#include"queue_arr.h"
int main(){
arr *a=create();
	deque(a);
	int i;
	for(i=1;i<=10;i++)
		enque(i,a);
	print(a);
	printf("\ndeque%d",deque(a));
	printf("\n%d",deque(a));
	printf("\n%d",deque(a));
	printf("\n%d",deque(a));
	print(a);
	printf("--------------------\n\n\n");
	//for(i=1;i<=100;i++)
		enque(i,a);
	print(a);
	
	printf("\n%d",deque(a));
	print(a);
	printf("\n%d",deque(a));
	printf("\n%d",deque(a));
	printf("\n%d",deque(a));
	printf("\n%d",deque(a));
	printf("\n%d",deque(a));
	printf("\n%d",deque(a));
	print(a);
	printf("\n%d",deque(a));
	printf("\n%d",deque(a));
	printf("\n%d",deque(a));
}