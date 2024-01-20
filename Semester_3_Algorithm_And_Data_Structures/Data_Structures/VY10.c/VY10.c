#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	struct n *right;
	int data;
	struct n *left;
}tree;

void travel(tree *a){
	if(a==NULL)
		return;
	//travel(a->right);
	travel(a->left);
	printf(" %d   ",a->data);
	//travel(a->left);
	travel(a->right);
}

int find(tree *a,int x){
	if(a==NULL)
		return 0;
	if(a->data==x)
		return 1;
	if(a->data<x)
		find(a->right,x);
	else
		find(a->left,x);
}

tree * input(tree *a,int x){
	if(a==NULL){
		tree *node=(tree *)malloc(sizeof(tree));
		node->data=x;
		node->right=NULL;
		node->left=NULL;
		return node;
	}else{
		if(a->data<x)
			a->right=input(a->right,x);
		else
			a->left=input(a->left,x);
		return a;
	}
}
int max(tree *a){
	if(a==NULL){
		printf("\nThis Tree is Empty!\n");
		return 0;
	}
	while(a->right!=NULL)
		a=a->right;
	return a->data;
}
int min(tree *a){
	if(a==NULL){
		printf("\nThis Tree is Empty!\n");
		return 0;
	}

	while(a->left!=NULL)
		a=a->left;
	return a->data;
}
tree *delete(tree * a,int x){
	if(a==NULL){
		printf("\ndon't remove integer.\n");
		return NULL;
	}
	if(a->data==x){
		if(a->right==NULL&&a->left==NULL)
			return NULL;
		if(a->right!=NULL){
			a->data=min(a->right);
			a->right=delete(a->right,min(a->right));
		}else{
			a->data=max(a->left);
			a->left=delete(a->left,max(a->left));
		}
		return a;
	}else if(a->data<x){
		a->right=delete(a->right,x);
		return a;
	}else{
		a->left=delete(a->left,x);
		return a;
	}
}
int main(){
	tree *a=NULL;
	a=input(a,56);
	a=input(a,200);
	a=input(a,26);
	a=input(a,18);
	a=input(a,27);
	a=input(a,190);
	a=input(a,28);
	a=input(a,12);
	a=input(a,24);
	a=input(a,213);
	a=input(a,113);
	printf("%s \n\n",find(a,11)? "Var":"Yok");
	travel(a);
	printf("\nMin: %d Max: %d\n",min(a),max(a));
	a=delete(a,206);
	travel(a);
}