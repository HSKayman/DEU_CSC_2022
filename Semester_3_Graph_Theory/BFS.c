#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct{
	int *ar;
	int size;
	int end;
	int start;
	int ram;
}que;
que *create(int x){
	que *a=(que *)malloc(sizeof(que));
	a->ram=x;
	a->ar=(int *)malloc(sizeof(int)*a->ram);
	a->start=0;
	a->size=0;
	a->end=0;
	return a;
}
void enque(que *a,int x){
	if(a->size<a->ram){
		a->ar[a->start]=x;
		a->start=(a->start+1)%a->ram;
		++a->size;
	}else{
		printf("\nListe dolu veya kullanim hakki bitmistir.\n");
	}
}
int deque(que *a){
	if(0<a->size){
		int x=a->ar[a->end];
		a->end=(a->end+1)%a->ram;
		--a->size;
		return x;
	}else{
		return -1;
	}
}
int ctr(bool *v,int i){
	i-=1;
	while(i>-1){
		if(v[i]==false)
			return i;
		--i;
	}
	return -1;
}
void BFS(bool **a,int size,int start){
	bool *visited=(bool *)malloc(sizeof(bool)*size);
	int i=0;
	while(i<size){
		visited[i]=false;
		++i;		
	}
	i=start;
	que *node=create(size+1);
	visited[i]=true;
	while(ctr(visited,size)!=-1){
		int j;
		printf("%d\n",i);
		visited[i]=true;
		for(j=0;j<size;j++){
			if(a[i][j]&&!visited[j]){
				visited[j]=true;
				enque(node,j);
			}
		}
	i=deque(node);
	if(i==-1)
		if(ctr(visited,size)!=-1)
			i=ctr(visited,size);
	}
}
int main(){
		n1:
	printf("\nLutfen Matrisiniz Ilk Satirinizi (-1) e Basincaya Kadar Giriniz\n");
	int cc=10;
	bool *b=(bool *)malloc(cc*sizeof(bool));
	int i=0;
	do{
		int f;
		printf("\n a[0][%d]: ",i);
		scanf("%d",&f);
		if(f!=-1){
			i++;
			if(cc-1<=i){
				cc+=10;
				b=(bool *)realloc(b,cc*sizeof(bool));
			}
			if(f==1)
				b[i-1]=true;
			else if(f==0)
				b[i-1]=false;
			continue;
		}else
			break;
	}while(1);
		
	int c,v=i;
	bool **a=(bool **)malloc(v*sizeof(bool *));
	a[0]=(bool *)malloc(v*sizeof(bool));
	
	for(i=0;i<v;i++)
		a[0][i]=b[i];
	free(b);
	
	for(i=1;i<v;i++){
		a[i]=(bool *)malloc(v*sizeof(bool));
		int j;
		for(j=0;j<v;j++){
			printf("\n a[%d][%d]: ",i,j);
			int f;
			scanf("%d",&f);
			if(f==1)
				a[i][j]=true;
			else if(f==0)
				a[i][j]=false;
		}
	}
	int j;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			printf("\t %s",a[i][j] ? "true" : "false");
		printf("\n");
	}
	BFS(a,v,0);
}