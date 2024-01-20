#include<stdio.h>
#include<string.h>
int main(){
    int A[3][3]={{0,2,3},{2,0,2},{3,2,0}},i,j,k,C[3][3]={0};
    char S[3][3]={{'-','2','3'},{'1','-','3'},{'1','2','-'}};
    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
            for(k=0;k<3;++k)
                C[i][j]+=A[i][k]*A[k][j];
    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
            for(k=0;k<3;++k)
                printf("%d %d  %c->%c\n",i,j,S[i][k],S[k][j]);
    for(i=0;i<3;++i){
        for(j=0;j<3;++j)
            printf("%5d",C[i][j]);
        printf("\n");
    }
}