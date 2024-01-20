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
	}else if(rroot->next==NULL){
		int rvalue=rroot->data;
		node * temp=NULL;
		*root=temp;
		free(rroot);
		return rvalue;
	}else{
		while(rroot->next->next!=NULL)
			rroot=rroot->next;
		int rvalue=rroot->next->data;
		rroot->next=NULL;
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
		node *temp=(node *)malloc(sizeof(node));
		temp->data=x;
		temp->next=root;
		return temp;
	}
}