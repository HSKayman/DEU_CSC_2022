#include<stdio.h>
#include<stdlib.h>
#include"stack_ll.h"
int main(){
	node *s=NULL;
	int i;
	printf("\npopped%d",pop(&s));
	s=push(s,8710);
	printf("\npopped%d",pop(&s));
	for(i=0;i<10;i++)
		s=push(s,i*10);
	print(s);
	printf("\npopped%d",pop(&s));
	print(s);
	printf("\npopped%d",pop(&s));
	printf("\npopped%d",pop(&s));
	printf("\npopped%d",pop(&s));
	printf("\npopped%d",pop(&s));
}