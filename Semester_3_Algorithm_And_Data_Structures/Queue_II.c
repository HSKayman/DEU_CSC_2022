#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	short int *self;
	short int size;
	short int start;
	short int end;
	short int count;
} array;
array *create(short int size){
	array *new=(array *)malloc(sizeof(array));
	new->size=size;
	new->start=0;
	new->end=0;
	new->count=0;
	new->self=(short int *)malloc(sizeof(short int)*size);
	return new;
}
short int deque(array * pro){
	if(pro->count<=0){
		printf("\nQue is Empty!");
		return -1;
	}
	else{
		short int v=pro->self[pro->start];
		pro->start=(pro->start+1)%pro->size;
		pro->count--;
		return v;
	}
}
void enque(short int x,array * pro){
	if(pro->count>=pro->size)
		printf("\nQue is Full!");
	else{
		pro->self[pro->end]=x;
		pro->count++;
		pro->end=(pro->end+1)%10;
	}
}
void print(array * pro){
	short int i;
	if(pro->count==0)
		printf("\nQue is Empty!");
	for(i=pro->start;i!=pro->end;i=(i+1)%(pro->size))
		printf("\n%d)   %d",i,pro->self[i]);
	printf("\n\n\n\n\n\n");
}
void shortingenque(short int x,array * pro,short int y){
	if(y-1>=pro->count||pro->count>=pro->size||y-1>=pro->size)
		printf("\nWrong Value Or Que is Full");
	else{
		short int i=0;
		array *value=create(pro->size);
		while(i<y-1){
			enque(deque(pro),value);
			i++;
		}
		enque(x,value);
		while(pro->count>0)
			enque(deque(pro),value);
		while(value->count>0)
			enque(deque(value),pro);
		
		free(value);
		
	}
}

void main(){
	array *new=create(10);
	short int i;
	//for(i=0;i<7;i++)
	//	enque(i*10,new);
	//print(new);
	for(i=0;i<8;i++)
		printf("\n %d",deque(new));
	//print(new);
	for(i=0;i<7;i++)
		enque(i*10,new);
	//print(new);
	shortingenque(55,new,3);
	print(new);


}