#include<stdio.h>
#include<stdlib.h>
#include"queue_arr.h"
arr *create(void){
	arr *a=(arr *)malloc(sizeof(int));
	a->size=2;
	a->scount=0;
	a->count=0;
	a->array=(int *)malloc(sizeof(int));
	return a;
}
void print(arr *a){
	int i;
	for(i=a->scount;i<a->count;i++)
		printf("\n  %d",a->array[i]);
}
int deque(arr *a){
	if(a->scount>=a->count){
		printf("\nThis Array is Empty\n");
		return -1;
	}else if(a->size/4>=((a->count)-(a->scount))){
		int *array2=(int *)malloc(sizeof(int)*a->size/2),i,c=0;
		for(i=a->scount;i<a->count;i++)
			array2[c++]=a->array[i];
		free(a->array);
		a->array=array2;
		a->size/=2;
		a->count=c;
		a->scount=0;
		return a->array[a->scount++];
	}
	return a->array[a->scount++]; 
}

void enque(int x,arr *a){
	if(a->count+1>=a->size){
		int *array2=(int *)malloc(sizeof(int)*a->size*2),i;
		for(i=a->scount;i<=a->count;i++)
			array2[i]=a->array[i];
		free(a->array);
		a->array=array2;
		a->size*=2;
	}
	a->array[a->count++]=x;	
}
