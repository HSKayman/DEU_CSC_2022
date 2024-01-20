#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>
#include<omp.h>
int main(int argc, char **argv){
   
    /*
    #pragma omp parallel
    {
        int tid=omp_get_thread_num();
        #pragma omp for
        for(int i=0;i<10;++i)
            printf("%u proces belongs to %i. Thread\n",i,tid);
    }

    #pragma omp parallel for
    for(int i=0;i<10;++i){
        int tid=omp_get_thread_num();
        printf("!%u proces belongs to %i. Thread\n",i,tid);
    }*/

    uint32_t j,i,n=16, number_t, **series;
    if (argc != 3){
        printf("Missing Arg!\n");
        return 0;
    }
    number_t=atoi(argv[1]);
    n=atoi(argv[2]);
    //omp_set_dynamic(0);
    omp_set_num_threads(number_t); 
    number_t=omp_get_max_threads();
    
    
    series=(uint32_t**)malloc(n*sizeof(uint32_t*));
    for(i=0;i<n;++i)
        series[i]=(uint32_t*)malloc(n*sizeof(uint32_t));



    #pragma omp parallel for
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            //printf("i=%u j=%u proces belongs to %u. Thread\n",i,j,omp_get_thread_num());
            series[i][j]=omp_get_thread_num();
        }
    }

    for(i=0;i<n;++i){
        for(j=0;j<n;++j)
            printf("%u ",series[i][j]);
        printf("\n");
    }printf("\n");printf("\n");

    for(i=0;i<n;++i){
        #pragma omp parallel for
        for(j=0;j<n;++j){
            //printf("i=%u j=%u proces belongs to %u. Thread\n",i,j,omp_get_thread_num());
            series[i][j]=omp_get_thread_num();
        }
    }


    for(i=0;i<n;++i){
        for(j=0;j<n;++j)
            printf("%u ",series[i][j]);
        printf("\n");
    }printf("\n");printf("\n");

    #pragma omp parallel for collapse(2)
    for(i=0;i<n;++i){ 
        for(j=0;j<n;++j){
            //printf("i=%u j=%u proces belongs to %u. Thread\n",i,j,omp_get_thread_num());
            series[i][j]=omp_get_thread_num();
        }
    }

    for(i=0;i<n;++i){
        for(j=0;j<n;++j)
            printf("%u ",series[i][j]);
        printf("\n");
    }printf("\n");printf("\n");
}