#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
void dijkstra(int **,int,int);
int minDistance(int *,bool*,int);
void print(int *,int);
bool control(int **,int);
int main(){ 
/*n1:
	printf("\nLutfen Matrisiniz Ilk Satirinizi (-1) e Basincaya Kadar Giriniz Belli Olmayanlara -2 Giriniz\n");
	int cc=10;
	int *b=(int *)malloc(cc*sizeof(int));
	int i=0;
	do{
		int f;
		printf("\n a[0][%d]: ",i);
		scanf("%d",&f);
		if(f!=-1){
			i++;
			if(cc-1<=i){
				cc+=10;
				b=(int *)realloc(b,cc*sizeof(int));
			}
			if(f!=-2)
				b[i-1]=f;
			else
				b[i-1]=SHRT_MAX;
			continue;
		}else
			break;
		
	}while(1);
		
	int c,v=i;
	int **a=(int **)malloc(v*sizeof(int *));
	a[0]=(int *)malloc(v*sizeof(int));
	
	for(i=0;i<v;i++)
		a[0][i]=b[i];
	free(b);
	
	for(i=1;i<v;i++){
		a[i]=(int *)malloc(v*sizeof(int));
		int j;
		for(j=0;j<v;j++){
			printf("\n a[%d][%d]: ",i,j);
			int f;
			scanf("%d",&f);
			if(f!=-2)
				a[i][j]=f;
			else
				a[i][j]=SHRT_MAX;
		}
	}
	
	if(!control(a,v)){
		printf("\n Matris Yanlis! ,Tekrar Deneyiniz!\n");	
		goto n1;
	}*/
	int v=6;
	int b[6][6]={{0,7,4,SHRT_MAX,2,SHRT_MAX},
				{7,0,3,2,SHRT_MAX,6},
				{4,3,0,8,1,SHRT_MAX},
				{SHRT_MAX,2,8,0,10,3},
				{2,SHRT_MAX,1,10,0,SHRT_MAX},
				{SHRT_MAX,6,SHRT_MAX,3,SHRT_MAX,0}};
	int i,**a=(int **)malloc(v*sizeof(int *));
	for(i=0;i<6;i++){
		a[i]=(int *)malloc(v*sizeof(int));
		int j;
		for(j=0;j<v;j++)
			a[i][j]=b[i][j];
	}
  	dijkstra(a,0,v); 
  	return 0; 
}
void print(int *a,int V){ 
  	int i;
    for(i=0;i<V;++i) 
        printf("%d \t\t %d\n", i, a[i]);  
}
int minDistance(int *dist, bool *sptSet,int V){ 
    int min=SHRT_MAX,index; 
  	int v;
    for (v=0;v<V;++v) 
        if (!sptSet[v]&&dist[v]<=min) 
            min=dist[v],index=v; 
    return index; 
} 
void dijkstra(int **g, int src,int V){ 
    int *dist=(int*)malloc(sizeof(int)*V); 
    bool *sptSet=(bool*)malloc(sizeof(bool)*V); 
    for(int i=0;i<V;++i) 
        dist[i]=SHRT_MAX,sptSet[i]=false; 
    dist[src]=0; 
    int count;
    for(count=0;count<V-1;++count){ 
        int u=minDistance(dist,sptSet,V); 
        sptSet[u]=true; 
        int v;
        for(v=0;v<V;++v)  
            if (!sptSet[v]&&g[u][v]&&dist[u]!=SHRT_MAX&&dist[u]+g[u][v]<dist[v]) 
                dist[v]=dist[u]+g[u][v]; 
    }
    print(dist,V); 
}
bool control(int **a,int v){
	int i,j;
	for(i=0;i<v;i++){
		if(a[i][i]!=0)
			return false;
		for(j=0;j<v;j++)
			if(a[i][j]!=a[j][i])
				return false;
	}
	return true;
}