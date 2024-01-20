#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//#include"AllLib.h"
typedef struct s{
	struct s *left,*right;
	int x;
}tree;

tree *create(int x){
	tree *root=(tree*)malloc(sizeof(tree));
	root->left=NULL;
	root->right=NULL;
	root->x=x;
	return root;
}

tree *input(tree *root,int x){
	if(root==NULL){
		root=create(x);
	}else{
		if(x>root->x)
			root->right=input(root->right,x);
		else
			root->left=input(root->left,x);
	}
	return root;
}

void traversal(tree *root){
	if(root==NULL)
		return;
	traversal(root->left);
	printf("%d ",root->x);
	traversal(root->right);
	return;
} 
int max(tree *root){
	if(root==NULL)
		return -1;
	else if(root->right==NULL)
		return root->x;
	else
		return max(root->right);
}
int min(tree *root){
	if(root==NULL)
		return -1;
	else if(root->left==NULL)
		return root->x;
	else
		return max(root->left);
}
bool find(tree *root,int x){
	if(root==NULL)
		return false;
	else if(root->x==x)
		return true;
	else{
		if(x>root->x)
			return find(root->right,x);
		else
			return find(root->left,x);
	}
}
tree *delete(tree *root,int x){
	if(root==NULL){
		printf("\ndon't remove integer.\n");
		return NULL;
	}
	if(root->x==x){
		if(root->right==NULL&&root->left==NULL)
			return NULL;
		if(root->right!=NULL){
			root->x=min(root->right);
			root->right=delete(root->right,min(root->right));
		}else{
			root->x=max(root->left);
			root->left=delete(root->left,max(root->left));
		}
		return root;
	}else if(root->x<x){
		root->right=delete(root->right,x);
		return root;
	}else{
		root->left=delete(root->left,x);
		return root;
	}
}
typedef struct n{
	int data;
	struct n *next;
}que;
void printq(que * n){
	while(n!=NULL){
		printf("->%d\n",n->data);
		n=n->next;
	}
}
que * enque(que *n, int x){
	if(n==NULL){
		n=(que *)malloc(sizeof(que));
		n->data=x;
		n->next=NULL;
		return n;
	}else{
		que *n2=NULL;
		n2=enque(n2,x);
		n2->next=n;
		return n2;
	}
}
int deque(que **nd){
	que *n=*nd;
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
typedef struct m{
	int data;
	struct m *next;
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