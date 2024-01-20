#include<stdio.h>
#include<stdlib.h>
#include"stack_ll.h"
int pop(node **proot){
	node *root=*proot;
	if(root==NULL){
		printf("\nThis Linked List is Empty\n");
		return -1;
	}else if(root->next==NULL){
			int rvalue=root->data;
			perror("GEctiiii");
			*proot=NULL;
			free(root);
			return rvalue;

	}else{
		node * iter=root;
		while(iter->next->next!=NULL)
			iter=iter->next;
		node * temp=iter->next;
		int rvalue=temp->data;
		iter->next=NULL;
		free(temp);
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
		node * iter=root;
		while(iter->next!=NULL)
			iter=iter->next;
		node *temp=(node *)malloc(sizeof(node));
		temp->data=a;
		iter->next=temp;
		temp->next=NULL;
		return root;
	}
}

void print(node *root){
	while(root!=NULL){
		printf("\n %d",root->data);
		root=root->next;
	}
}