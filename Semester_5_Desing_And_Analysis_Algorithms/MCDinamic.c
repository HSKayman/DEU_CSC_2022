#include<stdio.h>
#include<stdlib.h>
#define min(x,y) (x<y ? x:y)
#define n 4
#define m 4
#define max 5000
int main(){
    int cost[n+1][m+1]={{0,0,0,0,0},{0,0,2,100,4},{0,5,max,2,7},{0,max,9,3,1},{0,13,2,1,0}};
    int **a=(int **)calloc((n+1),sizeof(int*));
    int i,j;
    a[0]=(int*)calloc(m+1,sizeof(int));
    for(i=1;i<n+1;++i){
        a[i]=(int*)calloc(m+1,sizeof(int));
        for(j=1;j<m+1;++j){
            if(i>1&&j>1)
                a[i][j]=min(a[i-1][j],a[i][j-1])+cost[i][j];
            else if(i==1)
                a[i][j]=a[i][j-1]+cost[i][j];
            else if(j==1)
                a[i][j]=a[i-1][j]+cost[i][j];
            printf("%5d ",a[i][j]);
        }
        printf("\n");
    }
    if(a[n][m]<max)
        printf("%d",a[n][m]);
    return 0;
}