#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct n{
	struct n *right;
	char* data;
	struct n *left;
}tree;

void travel(tree *a){
	if(a==NULL)
		return;
	//travel(a->right);
	travel(a->left);
	printf(" %s   ",a->data);
	//travel(a->left);
	travel(a->right);
}

int find(tree *a,char *x,int c){
	if(a==NULL)
		return 0;
	if(strcmp(a->data,x)==0)
		c=find(a->right,x,c)+1;
	if(strcmp(a->data,x)>0)
		find(a->right,x,c);
	return c;
}

tree * input(tree *a,char *x){
	if(a==NULL){
		tree *node=(tree *)malloc(sizeof(tree));
		node->data=(char *)malloc(sizeof(char)*20);
		strcpy(node->data,x);
		node->right=NULL;
		node->left=NULL;
		return node;
	}else{
		if(strcmp(a->data,x)>0)
			a->right=input(a->right,x);
		else
			a->left=input(a->left,x);
		return a;
	}
}
char * max(tree *a){
	if(a==NULL){
		printf("\nThis Tree is Empty!\n");
		return 0;
	}
	while(a->right!=NULL)
		a=a->right;
	return a->data;
}
char * min(tree *a){
	if(a==NULL){
		printf("\nThis Tree is Empty!\n");
		return 0;
	}

	while(a->left!=NULL)
		a=a->left;
	return a->data;
}
tree *delete(tree * a,char * x){
	if(a==NULL){
		printf("\ndon't remove integer.\n");
		return NULL;
	}
	if(strcmp(a->data,x)==0){
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
	}else if(strcmp(a->data,x)>0){
		a->right=delete(a->right,x);
		return a;
	}else{
		a->left=delete(a->left,x);
		return a;
	}
}
int main(){
	tree *a=NULL;
	a=input(a,"56");
	a=input(a,"a");
	a=input(a,"A");
	a=input(a,"A");
	//travel(a);
	printf("%d",find(a,"A",0));
}