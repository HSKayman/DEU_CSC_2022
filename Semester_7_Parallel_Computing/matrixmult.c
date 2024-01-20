#include<stdio.h>
#include<omp.h>
#define N 4

int main(){
    int A[N][N]={{3,7,3,6},{9,2,0,3},{0,2,1,7},{2,2,7,9}};
    int B[N][N]={{6,5,5,2},{1,7,9,6},{6,6,8,9},{0,3,4,2}};
    int C[N][N]={0};
    int i,j,k;
    #pragma omp parallel private(k)
    {
        #pragma omp for collapse(2)
        for(i=0;i<N;++i)
            for(j=0;j<N;++j)
                for(k=0;k<N;++k){
                    C[i][j]+=A[i][k]*B[k][j];
                    //printf("%u\n",k);
                }
    }
    for(i=0;i<N;++i){
            for(j=0;j<N;++j)
                printf("%d ",C[i][j]);
        printf("\n");
    }
}