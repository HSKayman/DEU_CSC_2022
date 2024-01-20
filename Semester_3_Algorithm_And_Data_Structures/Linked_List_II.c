#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	int x;
	struct n * next;
}node;

void print(node * root){
	while(root!=NULL){
		printf("\n %d",root->x);
		root=root->next;
	}
	printf("\n\n\n---------------------------------------------\n\n\n");
}

void input(node * root,int x){
	while(root->next!=NULL){
		root=root->next;
	}
	root->next=(node *)malloc(sizeof(node));	
	root->next->x=x;
	root->next->next=NULL;
}
node *sortintput(node *r,int x){
	if(r==NULL){
		r=(node *)malloc(sizeof(node));
		r->next=r;
		r->x=x;
		return r;
	}
	if(r->x>x){
			node * temp =(node *)malloc(sizeof(node));
			temp->x=x;
			temp->next=r;
			node * iter=r;
			return temp;
		}
	node * iter=r;
	while(iter->next!=NULL && iter->next->x<x){
		iter=iter->next;
	}
	node * temp =(node *)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=x;
	return r;
}

node * delete(node * root,int x){
	node * maintemp=root;
	if(root->x==x){
		node * temp=root;
		root=root->next;
		free(temp);
		return root;
	}else{
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
			free(temp);
			return maintemp;
		}
	}
}
int main(){
	node * root=(node *)malloc(sizeof(node));
	root->x=0;
	root->next=NULL;
	int i;
	for(i=0;i<10;i++){
		root=sortintput(root,(i+1)*10);
	}
	print(root);
	root=sortintput(root,-1);
	root=sortintput(root,110);
	root=sortintput(root,55);
	print(root);
}