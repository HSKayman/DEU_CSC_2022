#include<stdio.h>
#include<stdlib.h>
#include"stack_arr.h"
stack * def(){
	stack *s=(stack *)malloc(sizeof(stack));
	s->array=NULL;
	s->size=2;
	s->top=0;
	return s;
}
int pop(stack *s){
	if(s->top<=0||s->array==NULL){
		printf("\nThe Array is Empty\n");
		return -1;
	}
	if(s->top<=s->size/4){
		int *array2=(int *)malloc(s->size/2*sizeof(int)),i;
		for(i=0;i<s->top;i++)
			array2[i]=s->array[i];
		free(s->array);
		s->array=array2;
		s->size/=2;
	}
	return s->array[--s->top];
}

void push(int a,stack *s){
	if(s->array==NULL)
		s->array=(int *)malloc(2*sizeof(int));
	if(s->top+1>=s->size){
		int *array2=(int *)malloc(s->size*2*sizeof(int)),i;
		for(i=0;i<s->top;i++)
			array2[i]=s->array[i];	
		free(s->array);
		s->array=array2;
		s->size*=2;
	}
	s->array[s->top++]=a;
}

void print(stack *s){
	int i;
	for(i=0;i<s->top;i++)
		printf("\n  %d",s->array[i]);
}