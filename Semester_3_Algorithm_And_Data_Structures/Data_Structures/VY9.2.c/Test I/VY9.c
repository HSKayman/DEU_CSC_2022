#include<stdio.h>
#include<stdlib.h>
#include"queu_ll.h"

int main(){
	node *root=NULL;
	int i;
	printf("\n %d",deque(&root));
	for(i=1;i<11;i++)
		root=enque(i*10,root);
	print(root);
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	printf("\n %d",deque(&root));
	root=enque(i*10,root);
	print(root);
}