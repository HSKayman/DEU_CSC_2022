#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	int x;
	struct n * next;
};
typedef struct n node;
int main () {
	node * root,*inter;
	root =(node *)malloc(sizeof(node));
	inter=root;
	int i;
	for(i=0;i<5;i++){
		inter -> x = i;
		inter-> next=(node *)malloc(sizeof(node));
		inter= inter->next;
	}
	for(i=0;i<5;i++){
		printf("\n %d",root->x);
		root=root->next;
	}
}
