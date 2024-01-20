#include<stdio.h>
int main(){
    int i,j,k,count=0;
    for(i=1;i<10;++i)
        for(j=i+1;j<10;++j)
            for(k=j+1;k<10;++k){
                printf("%d%d%d\n",i,j,k);
                ++count;
            }
    printf("Number Of thing which in up :%d",count);
}