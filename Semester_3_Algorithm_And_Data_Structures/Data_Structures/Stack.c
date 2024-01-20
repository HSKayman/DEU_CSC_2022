#include<stdio.h>
#include<stdlib.h>
int main(){
	int i;
	stack *a=create();
	for(i=0;i<21;i++){
		push(a,i*10);
		printf("%d-%d\n",a->s,a->size);
	}
	for(i=0;i<20;i++){
		pop(a);
		printf("%d-%d\n",a->s,a->size);
	}
	printf("\n\n\n-----a-----\n\n\n\n");
	print(a);
}
/*//Level 1///

int ar[10];
int top=0;
int start=0;
void push(int x){
	if(top<10){
		int i;
		for(i=8;i>-1;i--){
			ar[i+1]=ar[i];
		}
		top++;
		ar[0]=x;
	}else{
		printf("\nYer yok aq\n");
	}
}
int pop(){
	if(top!=0){
		int i,x=ar[0];
		for(i=0;i<9;i++){
			ar[i]=ar[i+1];
		}
		top--;
		return x;
	}else
		return -1;
	
}*/


/*//Level 2///
int ar[10],s=0;
void print(){
	for(int i=s-1;i>-1;i--)
		printf("%d\n",ar[i]);
}
void push(int x){
	if(s<10){
		ar[s]=x;
		s+=1;
	}else{
		printf("\nYer yok aq\n");
	}
}
int pop(){
	if(s!=0){
		s-=1;
		return ar[s];
	}else
		return -1;
	
}*/


/*//Level 3///
typedef struct {
	int *array;
	int s;
}stack;
stack * create(){
	stack *a=(stack *)malloc(sizeof(stack));
	a->s=0;
	return a;
}
void print(stack *a){
	int i;
	for(i=a->s-1;i>-1;i--)
		printf("%d\n",a->array[i]);
}
void push(stack *a,int x){
	if(a->s<10){
		a->array[a->s++]=x;
	}else{
		printf("\nYer yok aq\n");
	}
}
int pop(stack *a){
	if(a->s!=0){
		return a->array[--a->s];
	}else
		return -1;
	
}*/


/*//Level 4///
typedef struct {
	int size;
	int *array;
	int s;
}stack;
stack * create(){
	stack *a=(stack *)malloc(sizeof(stack));
	a->s=0;
	a->size=2;
	a->array=(int *)malloc(sizeof(int)*a->size);
	return a;
}
void print(stack *a){
	int i;
	for(i=a->s-1;i>-1;i--)
		printf("%d\n",a->array[i]);
}
void push(stack *a,int x){
	if(a->s+1<a->size){
		a->array[a->s++]=x;
	}else{
		a->size*=2;
		a->array=(int *)realloc(a->array,sizeof(int)*a->size);
		a->array[a->s++]=x;
	}
}
int pop(stack *a){
	if(a->s!=0){
		return a->array[--a->s];
	}else
		return -1;
	
}*/
/*//Level 5///
typedef struct {
	int size;
	int *array;
	int s;
}stack;
stack * create(){
	stack *a=(stack *)malloc(sizeof(stack));
	a->s=0;
	a->size=2;
	a->array=(int *)malloc(sizeof(int)*a->size);
	return a;
}
void print(stack *a){
	int i;
	for(i=a->s-1;i>-1;i--)
		printf("%d\n",a->array[i]);
}
void push(stack *a,int x){
	if(a->s+1<a->size){
		a->array[a->s++]=x;
	}else{
		a->size*=2;
		a->array=(int *)realloc(a->array,sizeof(int)*a->size);
		a->array[a->s++]=x;
	}
}
int pop(stack *a){
	if(a->s!=0){
		if(a->s*3<=a->size){
			a->size/=2;
			a->array=(int *)realloc(a->array,sizeof(int)*a->size);
		}
		return a->array[--a->s];
	}else
		return -1;
	
}*/