#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
bool search(node *n,int x){
	while(n!=NULL){
		if(x==n->data)
			return true;
		n=n->next;
	}
	return false;
}
node * push(node *n,int x){
	if(n==NULL){
		n=(node *)malloc(sizeof(node));
		n->data=x;
		n->next=NULL;
		return n;
	}else{
		node *n2=NULL;
		n2=push(n2,x);
		n2->next=n;
		return n2;
	}
}
node *sortingpush(node *n,int x){
	if(n==NULL){
		n=(node *)malloc(sizeof(node));
		n->data=x;
		n->next=NULL;
		return n;
	}else if(x<=n->data){
		node *n2=NULL;
		n2=sortingpush(n2,x);
		n2->next=n;
		return n2;
	}else{
		node *n3=n;
		while(n->next!=NULL){ 
			if(n->data<=x&&x<n->next->data)
				break;
			n=n->next;
		}
		if(n->next==NULL){
			node *n2=NULL;
			n->next=sortingpush(n2,x);
			return n3;
		}else{
			node *n2=n->next;
			node *n4=NULL;
			n4=sortingpush(n4,x);
			n->next=n4;
			n4->next=n2;
			return n3;
		}
	}
}
node *delete(node *n,int x){
	if(n==NULL){
		printf("\nThis Linked List is Empty!\n");
		return NULL;
	}else if(n->data==x){
			node *n2=n->next;     
			free(n);
			/*if(search(n2,x))  
				n2=delete(n2,x);*/
			return n2;
	}else{
		node *n2=n;
		while(n->next!=NULL){
			if(n->next->data==x)
				break;
			n=n->next;
		}
		if(n->next==NULL)
			return n2;
		else{
			node *n3=n->next;
			n->next=n->next->next;
			free(n3);
			/*if(search(n2,x))
				n2=delete(n2,x);*/
			return n2;
		}	
	}
}
node *alldelete(node *n,int x){
	while(search(n,x)){
		n=delete(n,x);
	}
	return n;
}
int main(){
	int i;
	node *n=NULL;
	for(i=16;i>4;--i){
		n=sortingpush(n,10);
		n=sortingpush(n,i);
	}
	
	
	print(n);
	//printf("\n-------------n------------\n");
	n=alldelete(n,10);
	print(n);
}