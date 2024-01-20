#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	int data;
	struct n *next;
}node;
void print(node *n){
	while(n!=NULL){
		printf("\n->%d\t",n->data);
		n=n->next;
	}
}
node * push(node *n,int x){
	if(n==NULL){
		n=(node *)malloc(sizeof(node));
		n->data=x;
		n->next=NULL;
		return n;
	}else{
		node *n2=n;
		while(n->next!=NULL)
			n=n->next;
		n->next=push(n->next,x);
		return n2;
	}
}
int pop(node **nd){
	node *n=*nd;
	if(n==NULL){
		printf("\nThe Stack is Empty\n");
		return -1;
	}else if(n->next==NULL){
		int x=n->data;
		*nd=NULL;
		free(n);
		return x;
	}else{
		while(n->next->next!=NULL)
			n=n->next;
		int x=n->next->data;
		free(n->next);
		n->next=NULL;
		return x;
	}
}
int main(){
	int i;
	node *n=NULL;
	for(i=0;i<30;++i)
		n=push(n,i*10);
	print(n);
}