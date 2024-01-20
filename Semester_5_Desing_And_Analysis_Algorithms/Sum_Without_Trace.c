#include<stdio.h>
#include<stdlib.h>
int SumMatrix(int **matrix,int size){
    int i,j,sum=0;
    for(i=0;i<size-1;++i)
        for(j=i+1;j<size;++j)
            sum+=matrix[i][j]+matrix[j][i];
    return sum;
}
int SumMatrixII(int **matrix,int size){
    int i,j,sum=0;
    for(i=0;i<size-1;++i)
        for(j=i+1;j<size;++j)
            sum+=matrix[size-1-i][size-1-j]+matrix[size-1-j][size-1-i];
    return sum;
}
int main(){
    int size=3;
    int i,j,**matrix=(int **)malloc(size*sizeof(int *));
    for(i=0;i<size;++i){
        matrix[i]=(int *)malloc(size*sizeof(int));
        for(j=0;j<size;++j)
            matrix[i][j]=i*size+(j+1);
    }
    printf("%d",SumMatrix(matrix,3));
    printf("%d",SumMatrixII(matrix,3));
}