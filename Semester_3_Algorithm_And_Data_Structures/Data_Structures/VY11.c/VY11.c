#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	struct n *right;
	int x;
	struct n *left;
}heap;
heap *input(heap *root,int x){
	if(root==NULL){
		root=(heap *)malloc(sizeof(heap));
		root->x=x;
		root->right=NULL;
		root->left=NULL;
		return root;
	}else if(root->left==NULL){
		return input(root->left,x);
	}else if(root->right==NULL){
		return input(root->right,x);
	}
}