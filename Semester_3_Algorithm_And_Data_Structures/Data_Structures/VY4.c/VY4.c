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
}

void input(node * root,int x){
	while(root->next!=NULL){
		root=root->next;
	}
	root->next=(node *)malloc(sizeof(node));	
	root->next->x=x;
	root->next->next=NULL;
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
		input(root,(i+1)*10);
	}
	print(root);
	printf("\n\n\n---------------------------------------------\n\n\n");
	root=delete(root,110);
	print(root);
}