#include<stdio.h>
#include<stdlib.h>
void Pascal_Tree(int n){
    int **array=(int **)malloc(n*sizeof(int));
    int i,j;
    for(i=0;i<n;++i){
        array[i]=(int *)malloc(sizeof(int)*(i+1));
        for(j=0;j<=i;++j){
            if(j==0 || j==i){
                array[i][j]=1;
                printf("1 ");
            }else{
                array[i][j]=array[i-1][j]+array[i-1][j-1];
                printf("%d ",array[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n The Tree is created Like Up.");
    
}
int main(){
    Pascal_Tree(10);
}