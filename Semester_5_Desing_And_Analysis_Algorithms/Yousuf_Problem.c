#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int sum(int *a,int size){
    int sum=0,i;
    for(i=0;i<size;++i)
        sum+=a[i];
    return sum;
}
int findIndex(int size,int index){
    if(index+1==size)
        return 0;
    return index+1;
    
}
int Yousuf_Problem(int x){
    int *number=(int *)malloc(x*sizeof(int)),i,j;
    for(i=0;i<x;++i)
        number[i]=1;
    for(i=0;sum(number,x)!=1;i=findIndex(x,i))
        if(number[i]==1){
            for(j=findIndex(x,i);;j=findIndex(x,j))
                if(number[j]==1){
                    number[j]=0;
                    break;
                }
        }
    for(i=0;i<x;++i)
        if(number[i]==1)
            return i+1;
}
int main(){
    int N=128,i;
    clock_t begin = clock();
    for(i=2;i<N;++i){
        printf("%d) %d\n",i,Yousuf_Problem(i));
    }
    clock_t end = clock();
    printf("Time Spent Of Bad Algorithm : %lf\n",(double)(end - begin) / CLOCKS_PER_SEC);
	printf("\n---------\n");
    begin = clock();
    for(i=2;i<N;++i){
        printf("%d) %d\n",i,(int)(2*(i-pow(2,floor(log2(i))))+1));
    }
    end=clock();
    printf("Time Spent Of Good Algorithm : %lf\n",(double)(end - begin) / CLOCKS_PER_SEC);
	printf("\n---------\n");
}