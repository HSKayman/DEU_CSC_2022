#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	int data;
	struct n *next;
}node;
void print(node * n){
	while(n!=NULL){
		printf("->%d\n",n->data);
		n=n->next;
	}
}
node * enque(node *n, int x){
	if(n==NULL){
		n=(node *)malloc(sizeof(node));
		n->data=x;
		n->next=NULL;
		return n;
	}else{
		node *n2=NULL;
		n2=enque(n2,x);
		n2->next=n;
		return n2;
	}
}
int deque(node **nd){
	node *n=*nd;
	if(n==NULL){
		printf("\nThis Que is Empty!\n");
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
		n=enque(n,i*10);
	print(n);
	for(i=0;i<30;++i)
		printf("\n%d",deque(&n));
	print(n);
	
}