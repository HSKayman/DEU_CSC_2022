#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
void Subset(int *array,int size){//for string char *
    int mask=1,i,j,count;
    for(i=0;i<pow(2,size);++i){
        count=i;
        printf("%d) ",i+1);
        for(j=0;count>0;++j){
            if(count&mask)
                printf("%d  ",array[j]);//for string %c
            count=count>>1;
        }
        printf("\n");
        
    }
}
int main(){
    int N=5;
    int i,*array=(int *)malloc(N*sizeof(int));
    for(i=0;i<N;++i)
        array[i]=i+1;
    clock_t begin = clock();
    Subset(array,N);
    clock_t end = clock();
	printf("Time Spent Of Bad Algorithm : %.16lf\n",(double)(end - begin)/CLOCKS_PER_SEC);
	printf("\n---------\n");
}