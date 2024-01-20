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


node * delete(node * root){
	node * maintemp=root;
	if(root==NULL){
		return root;
	}else if(root->next==NULL){
		node *temp=root->next;
		root->next=NULL;
		free(temp);
	}
	else{
		while(root->next->next!=NULL)
			root=root->next;
		node *temp=root->next;
		root->next=NULL;
		free(temp);
		return maintemp;
	}
}
int main(){
	node * root=(node *)malloc(sizeof(node));
	root->x=0;
	root->next=NULL;
	int i;
	for(i=0;i<10;i++){
		input(root,(i+1)*10);
	}
	print(root);
	root=delete(root);
	root=delete(root);
	root=delete(root);
	print(root);
}