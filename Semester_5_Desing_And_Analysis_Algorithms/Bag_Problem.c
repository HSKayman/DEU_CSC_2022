#include<stdio.h>
#include<stdlib.h>
#define max(x,y) (x>y ? x:y)
int main(){
    int n=4,b=8;
    int a[]={0,21,35,12,5};//Benefit
    int z[]={0,3,7,1,4};//Weight
    int **matrix=(int **)calloc((n+1),sizeof(int*));
    int i,j;
    matrix[0]=(int*)calloc(b+1,sizeof(int));
    for(i=1;i<n+1;++i){
        matrix[i]=(int*)calloc(b+1,sizeof(int));
        for(j=1;j<b+1;++j){
            if(z[i]<j+1)
                matrix[i][j]=max(matrix[i-1][j],a[i]+matrix[i-1][j-z[i]]);
            else
                matrix[i][j]=matrix[i-1][j];
            printf("%5d ",matrix[i][j]);
        }
        printf("\n");
    }
    i=n;
    j=b;
    printf("Solve Vector:\n\n");
    while(i>0 && j>0){
        if(matrix[i][j]!=matrix[i-1][j]){
            printf("%d. Element :Benefit:%10d, Weight:%10d\n",i,a[i],z[i]);
            j-=z[i];
        }
        --i;
    }
    return 0;
}