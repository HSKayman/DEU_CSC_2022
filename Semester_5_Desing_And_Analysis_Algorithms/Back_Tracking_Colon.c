#include<stdio.h>
#include<stdlib.h>
int main(){
    unsigned i,j,N=34,r=5;//N >r
    
    int **array=(int **)malloc((N+2)*sizeof(int));
    for(i=0;i<(N+2);++i){
        array[i]=(int *)malloc(sizeof(int)*(i+1));
        for(j=0;j<=i;++j)
            if(j==0 || j==i)
                array[i][j]=1;
            else
                array[i][j]=array[i-1][j]+array[i-1][j-1];
    }

    FILE *f=fopen("Answer.txt","w");

    for(i=0;i<N;++i){
        for(j=0;j<r;++j){
            if((i+1>j && i<r-1)||(i+2>r && i<N-r+1)||(i<j+1+N-r && i>N-r)){
                fprintf(f,"%10llu",(long long unsigned)array[i][j]*array[N-i-1][r-j-1]);   
            }
            else 
                fprintf(f,"%10d",0);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}