#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct v{
	int data;
	struct v *next;
}node;
int pop(node **nd);
void DFS(int **x, int y,int s);
int ctrlv(bool *v,int s);
void PDFS(int **x,int y,bool *v,bool *m,int s,node *n);
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
void DFS(int **x, int y,int s){
	bool *v=(bool *)malloc(sizeof(bool)*s);
	bool *m=(bool *)malloc(sizeof(bool)*s);
	short int i;
	tree *t=NULL;
	node *n=NULL;
	n=push(n,y);
	for(i=0;i<s;++i)
		v[i]=m[i]=false;
	PDFS(x,y,v,m,s,t,n);
}
int ctrlv(bool *v,int s){
	int i;
	for(i=0;i<s;++i){
		if(!v[i])
			return i;
	}
	return -2;
}
void PDFS(int **x,int y,bool *v,bool *m,int s,node *n){
	v[y]=true;
	m[y]=true;
	int i;
	bool f=true;
	for(i=0;i<s;++i){
		if(x[y][i]!=0&&!m[i]){
			f=false;
			n=push(n,i);
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
				printf("Birlestirilmis graf degil");
			}
		}
		else{
			PDFS(x,x3,v,m,s,t,n);
		}
	}
}