#include<stdio.h>
#include<stdlib.h>
#include"stack_ll.h"
int pop(node **root){
	if((*root)==NULL){
		printf("\nThis Linked List is Empty\n");
		return -1;
	}else if((*root)->next==NULL){
		int rvalue=(*root)->data;
		node *mayberoot=*root;
		*root=NULL;
		free(mayberoot);
		return rvalue;
	}else{
		node * mayberoot=*root;
		*root=(*root)->next;
		mayberoot->next=NULL;
		int rvalue=(mayberoot)->data;
		free(mayberoot);
		return rvalue;
	}
}

node * push(node *root,int a){
	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->data=a;
		root->next=NULL;
		return root;
	}else{
		node *temp=(node *)malloc(sizeof(node));
		temp->data=a;
		temp->next=root;
		return temp;
	}
}

void print(node *root){
	while(root!=NULL){
		printf("\n %d",root->data);
		root=root->next;
	}
}