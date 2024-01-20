#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
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
		return min(root->left);
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
int traversalforlevel(tree *root,int c){
	static int c2=0;
	if(c==1)
		c2=0;
	if(root==NULL)
		return 0;
	if(c2<c)
		c2=c;
	traversalforlevel(root->left,c+1);
	traversalforlevel(root->right,c+1);
	return c2;
} 

int level(tree *root){

	return traversalforlevel(root,1);
}

int main(){
	tree *r=create(1000);
	tree *f=create(10);
	r=input(r,500);
	r=input(r,300);
	r=input(r,750);
	r=input(r,625);
	r=input(r,650);
	r=input(r,1500);
	r=input(r,1250);
	r=input(r,1750);
	r=input(r,1600);
	r=input(r,1550);
	r=input(r,1575);
	traversal(r);
	printf("\n----------------\n");
	r=delete(r,1000);
	traversal(r);
}