#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct n{
	struct n * prev;
	int x;
	char *name;
	struct n * next;
}node;
void print(node * root){
	node * end=root;
	while(end->next!=NULL){
		end=end->next;
	}
	while(root!=NULL){
		printf("\n %d  %s",root->x,root->name);
		root=root->next;
		printf("\n %d  %s",end->x,end->name);
		end=end->prev;
	}
}
node *sortintput(node *r,int x,char *name){
	if(r==NULL){
		r=(node *)malloc(sizeof(node));
		r->prev=NULL;
		r->next=NULL;
		r->x=x;
		r->name=(char *)malloc(strlen(name)*sizeof('a'));
		strcpy(r->name,name);
		return r;
	}
	if(strcmp(r->name,name)>0){
			node * temp =(node *)malloc(sizeof(node));
			temp->x=x;
			temp->name=(char *)malloc(strlen(name)*sizeof('a'));
			strcpy(temp->name,name);
			temp->next=r;
			r->prev=temp;
			temp->prev=NULL;
			return temp;
		}
	node * iter=r;
	while(iter->next !=NULL&&strcmp(iter->next->name,name)<0){
		iter=iter->next;
	}
	node * temp =(node *)malloc(sizeof(node));
	temp->next=iter->next;
	if(iter->next!=NULL)
		iter->next->prev=temp;
	iter->next=temp;
	temp->prev=iter;
	temp->x=x;
	temp->name=(char *)malloc(strlen(name)*sizeof('a'));
	strcpy(temp->name,name);
	return r;
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
	root->name="Kerim";
	root->prev=NULL;
	root->next=NULL;
	root->x=0;
	int i;
	root=sortintput(root,10,"Ali");
	root=sortintput(root,20,"Veli");
	root=sortintput(root,30,"Deli");
	root=sortintput(root,40,"Seni");
	root=sortintput(root,50,"Seni Gidi Seni");
	root=sortintput(root,60,"Mali");
	root=sortintput(root,70,"Ahmet");
	root=sortintput(root,80,"Selami");
	root=sortintput(root,90,"Zeynel");
	print(root);
}