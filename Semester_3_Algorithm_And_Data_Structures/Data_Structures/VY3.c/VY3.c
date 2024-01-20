#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	int x;
	struct n * next;
};
typedef struct n node;
void prnt(node * k){
	while(k!=NULL){
		printf("\n %d",k->x);
		k=k->next;
	}
}
void input(node * k,int t){
	if(k!=NULL){
		while(k->next!=NULL)
			k=k->next;
		k->next=(node *)malloc(sizeof(node));
		k->next->x=t;
		k->next->next=NULL;
	}
}
void araya(node *k,int t,int s){
	int i=0;
	while(i<t-1){
		k=k->next;
		i+=1;
	}
	node * ekle=(node *)malloc(sizeof(node));
	ekle->x=s;
	ekle->next=k->next;
	k->next=ekle;
}
node *sortintput(node *r,int x){
	if(r==NULL){
		r=(node *)malloc(sizeof(node));
		r->next=NULL;
		r->x=x;
		return r;
	}
	node * iter=r;
	while(iter->next !=NULL&&iter->next->x<x){
		iter=iter->next;
	}
	if(r->x>x){
			node * temp =(node *)malloc(sizeof(node));
			temp->x=x;
			temp->next=r;
			return temp;
		}
	node * temp =(node *)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=x;
	return r;
}
int main () {
	node * root;
	//root =(node *)malloc(sizeof(node));
	//root->x=0;
	//inter=root;
	int i;
	//for(i=0;i<5;i++){
	//	inter-> next=(node *)malloc(sizeof(node));
	//	inter= inter->next;
	//	inter -> x = i*10+10;
	//}
	//inter->next=NULL;
	//prnt(root);
	//araya(root,3,4000);
	//prnt(root);
	//araya(root,5,5000);	
	for(i=65;i>0;i-=5)
		root=sortintput(root,i);	
	
	prnt(root);
	root=sortintput(root,567);
	root=sortintput(root,300);
	prnt(root);
}