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
	while(k->next!=NULL)
		k=k->next;
	k->next=(node *)malloc(sizeof(node));
	k->next->x=t;
	k->next->next=NULL;
}
int main () {
	node * root,*inter;
	root =(node *)malloc(sizeof(node));
	root->x=0;
	inter=root;
	int i;
	for(i=0;i<5;i++){
		inter-> next=(node *)malloc(sizeof(node));
		inter= inter->next;
		inter -> x = i*10+10;
	}
	inter->next=NULL;
	prnt(root);
	input(root,70);
	prnt(root);	
}