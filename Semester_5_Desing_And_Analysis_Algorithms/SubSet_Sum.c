#include<stdio.h>
#include<stdlib.h>
#define max(x,y) (x>y ? x:y)
int main(){
    int n=5,b=30;
    int a[]={0,3,7,8,2,5};
    int **matrix=(int **)calloc((n+1),sizeof(int*));
    int i,j;
    matrix[0]=(int*)calloc(b+1,sizeof(int));
    int flag=1;
    for(i=1;i<n+1&&flag;++i){
        matrix[i]=(int*)calloc(b+1,sizeof(int));
        for(j=1;j<b+1;++j){
            if(a[i]<j+1)
                matrix[i][j]=max(matrix[i-1][j],a[i]+matrix[i-1][j-a[i]]);
            else
                matrix[i][j]=matrix[i-1][j];
            printf("%5d ",matrix[i][j]);
            if(matrix[i][j]==b){
                flag=0;
                break;
            }
        }
        printf("\n");
    }
    --i;
    j=b;
    printf("Solve Vector:\n\n");
    while(i>0 || j>0){
        if(matrix[i][j]!=matrix[i-1][j]){
            printf("%10d",a[i]);
            j-=a[i];
        }
        --i;
    }
    return 0;
}