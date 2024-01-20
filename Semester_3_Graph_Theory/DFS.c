#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct v{
	int data;
	struct v *next;
}node;
typedef struct n{
	struct n *right;
	int data;
	struct n *left;
}tree;
void travel(tree *a);
void print(node *n);
node * push(node *n,int x);
int pop(node **nd);
void DFS(int **x, int y,int s);
int ctrlv(bool *v,int s);
void PDFS(int **x,int y,bool *v,bool *m,int s,tree* t,node *n);
tree * input(tree *a,int x,int y);
tree * create(tree *a,int x);
int main(){
	int a[7][7]={ {0,0,0,0,1,1,0},
				 {0,0,1,1,0,0,0},
				 {0,1,0,1,0,0,0},
				 {0,1,1,0,0,0,1},
				 {1,0,0,0,0,1,0},
				 {1,0,0,0,1,0,1},
				 {0,0,0,1,0,1,0}};
	int **x=(int **)malloc(7*sizeof(int*));
	int i,j;
	for(i=0;i<7;++i){
		x[i]=(int *)malloc(7*sizeof(int));
		for(j=0;j<7;++j){
			x[i][j]=a[i][j];
		}
	}
	DFS(x,0,7);
}
node * push(node *n,int x){
	if(n==NULL){
		n=(node *)malloc(sizeof(node));
		n->data=x;
		n->next=NULL;
		return n;
	}else{
		node *n2=n;
		while(n->next!=NULL)
			n=n->next;
		n->next=push(n->next,x);
		return n2;
	}
}
int pop(node **nd){
	node *n=*nd;
	if(n==NULL){
		return -1;
	}else if(n->next==NULL){
		int x=n->data;
		*nd=NULL;
		free(n);
		return x;
	}else{
		while(n->next->next!=NULL)
			n=n->next;
		int x=n->next->data;
		free(n->next);
		n->next=NULL;
		return x;
	}
}
void travel(tree *a){
	if(a==NULL)
		return;
	travel(a->left);
	printf(" %d   ",a->data);
	travel(a->right);
}
tree* input(tree *a,int x, int y){
	if(a==NULL)
		return a;
	else if(a->data==x){
		if(a->left==NULL){
			a->left=create(a->left,y);
			return a;
		}
		else{
			a->right=create(a->right,y);
			return a;
		}
	}
	a->left=input(a->left,x,y);
	a->right=input(a->right,x,y);
	return a;
}
tree * create(tree *a,int x){
	if(a==NULL){
		tree *node=(tree *)malloc(sizeof(tree));
		node->data=x;
		node->right=NULL;
		node->left=NULL;
		return node;
	}else{
		return a;
	}
}
void DFS(int **x, int y,int s){
	bool *v=(bool *)malloc(sizeof(bool)*s);
	bool *m=(bool *)malloc(sizeof(bool)*s);
	short int i;
	tree *t=NULL;
	node *n=NULL;
	t=create(t,y);
	n=push(n,y);
	for(i=0;i<s;++i)
		v[i]=m[i]=false;
	PDFS(x,y,v,m,s,t,n);
	travel(t);
}
int ctrlv(bool *v,int s){
	int i;
	for(i=0;i<s;++i){
		if(!v[i])
			return i;
	}
	return -2;
}
void PDFS(int **x,int y,bool *v,bool *m,int s,tree *t,node *n){
	v[y]=true;
	m[y]=true;
	int i;
	bool f=true;
	for(i=0;i<s;++i){
		if(x[y][i]!=0&&!m[i]){
			f=false;
			t=input(t,y,i);
			n=push(n,i);
			printf("%d %d %d\n",y,i,x[y][i]);
			PDFS(x,i,v,m,s,t,n);
		}
	}
	if(f){
		int x3=pop(&n);
		if(x3==-1){
			int x2=ctrlv(v,s);
			if(x2==-2){
				return;
			}
			else{
				PDFS(x,x2,v,m,s,t,n);
			}
		}
		else{
			PDFS(x,x3,v,m,s,t,n);
		}
	}
}