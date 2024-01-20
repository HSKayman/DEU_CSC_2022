#include<stdio.h>
#include<stdlib.h>

typedef struct n{
	struct n * prev;
	int x;
	struct n * next;
}node;

void print(node * root){
	while(root!=NULL){
		printf("\n %d",root->x);
		root=root->next;
	}
}

node *sortintput(node *r,int x){
	if(r==NULL){
		r=(node *)malloc(sizeof(node));
		r->prev=NULL;
		r->next=NULL;
		r->x=x;
		return r;
	}
	if(r->x>x){
			node * temp =(node *)malloc(sizeof(node));
			temp->x=x;
			temp->next=r;
			r->prev=temp;
			temp->prev=NULL;
			return temp;
		}
	node * iter=r;
	while(iter->next !=NULL&&iter->next->x<x){
		iter=iter->next;
	}
	node * temp =(node *)malloc(sizeof(node));
	temp->next=iter->next;
	if(iter->next!=NULL)
		iter->next->prev=temp;
	iter->next=temp;
	temp->prev=iter;
	temp->x=x;
	return r;
}

void input(node * root,int x){
	while(root->next!=NULL){
		root=root->next;
	}
	root->next=(node *)malloc(sizeof(node));	
	root->next->prev=root;
	root->next->x=x;
	root->next->next=NULL;
}

node * delete(node * root,int x){
	node * maintemp=root;
	if(root->x==x){
		node * temp=root;
		root=root->next;
		root->prev=NULL;
		free(temp);
		return root;
	}else{
		node * temp=root;
		while(root->next->x!=x){
			root=root->next;
			if(root->next==NULL)
				return maintemp;
		}
		if(root->next->next==NULL){
			free(root->next);
			root->next=NULL;
			return maintemp;
		}
		else{
			node * temp=root->next;
			root->next=root->next->next;
			root->next->prev=root;
			free(temp);
			return maintemp;
		}
	}
}


int main(){
	node * root=(node *)malloc(sizeof(node));
	root->prev=NULL;
	root->next=NULL;
	root->x=0;
	int i;
	for(i=0;i<5;i++){
		input(root,(i+1)*10);
	}
	print(root);
	sortintput(root,5);
	sortintput(root,999);
	print(root);
	sortintput(root,15);
	print(root);
	
	printf("\n\n\n---------------------------------------------\n\n\n");
	root=delete(root,999);
	print(root); 
	/*do{
		printf("\n %d",root->x);
		root=root->next;
	}while(root->next!=NULL);
	printf("\n %d",root->x);
	do{
		printf("\n  %d",root->x);
		root=root->prev;
	}while(root!=NULL);*/
}