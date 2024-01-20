#include<stdio.h>
#include<stdlib.h>
#include"queu_ll.h"

void print(node * root){
	printf("\n-------------------------------");
	while(root!=NULL){
		printf("\n %d",root->data);
		root=root->next;
	}
	printf("\n-------------------------------\n");
}
int deque(node **root){
	node *rroot=*root;
	if(rroot==NULL){
		printf("\nThis Linked List is Empty!\n");
		return -1;
	}else{
		int rvalue=rroot->data;
		*root=rroot->next;
		free(rroot);
		return rvalue;
	}
}
node * enque(int x,node*root){
	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->data=x;
		root->next=NULL;
		return root;
	}else{
		node *rroot=root;
		while(root->next!=NULL)
			root=root->next;
		node *temp=(node *)malloc(sizeof(node));
		temp->data=x;
		temp->next=NULL;
		root->next=temp;
		return rroot;
	}
}