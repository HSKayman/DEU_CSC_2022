#include<stdio.h>
#include<stdlib.h>
#include "stack_arr.h"

int main(){
	stack *s1=def(),*s2=def();
	int i;
	for(i=0;i<5;i++)
		push(i*10,s1);
	print(s1);
	for(i=0;i<5;i++)
		push(pop(s1),s2);	
	print(s2);
	print(s1);
}