#include<stdio.h>
#include<stdlib.h>

typedef struct n{
	int x;
	struct n * next;
}node;

void print(node * root){
	node * temp=root;
	do{
		printf("\n %d",root->x);
		root=root->next;
	}while(root!=temp);
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
			while(iter->next!=r)
				iter=iter->next;
			iter->next=temp;
			return temp;
		}
	node * iter=r;
	while(iter->next !=r&&iter->next->x<x){
		iter=iter->next;
	}
	node * temp =(node *)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=x;
	return r;
}

void input(node * root,int x){
	node * temp=root;
	while(root->next!=temp){
		root=root->next;
	}
	root->next=(node *)malloc(sizeof(node));	
	root->next->x=x;
	root->next->next=temp;
}

node * delete(node * root,int x){
	node * maintemp=root;
	if(root->x==x){
		node * temp=root;
		root=root->next;
		while(maintemp->next!=temp){
			maintemp=maintemp->next;
		}
		maintemp->next=root;
		free(temp);
		return root;
	}else{
		node * temp=root;
		while(root->next->x!=x){
			root=root->next;
			if(root->next==temp)
				return maintemp;
		}
		if(root->next->next==temp){
			free(root->next);
			root->next=temp;
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
	root->next=root;
	int i;
	for(i=0;i<2;i++){
		sortintput(root,(i+1)*10);
	}
	//sortintput(root,5);
	//sortintput(root,999);
	//sortintput(root,15);
	print(root);
	printf("\n\n\n---------------------------------------------\n\n\n");
	root=delete(root,999);
	print(root);
}