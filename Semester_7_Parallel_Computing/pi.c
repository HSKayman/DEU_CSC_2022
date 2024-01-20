#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <omp.h>
#define N 40
#define I 1000000
int main(){
    
    //omp_set_dynamic(0);
    uint32_t x,y,tsay = omp_get_max_threads();
    uint32_t i,*sum=(uint32_t *)calloc(tsay,sizeof(uint32_t)); 

    double zamanBasi = omp_get_wtime();
    srand(time(0));
    #pragma omp parallel private(i,x,y)
    {
        uint32_t tid = omp_get_thread_num();
        #pragma omp for
        for(i=0;i<I;++i)
        {
            x= rand()%(2*N);
            y= rand()%(2*N);
            if ((N-x)*(N-x)+(N-y)*(N-y)<=N*N) 
                sum[tid]+=1;
        }
        #pragma omp barrier 
        if(tid==0)
            for(i=1;i<tsay;++i)
                sum[tid]+=sum[i];
    }
    printf("\npi=%lf\n",(4.0)*(double)sum[0]/(I));

    double gecenZaman = omp_get_wtime() - zamanBasi;
    printf("Parallel: Gecen zaman = %.7f sn.\n", gecenZaman);

     //Serial 
    clock_t start_t, end_t;
    
    sum[0]=0;
    start_t = clock();
    for(i=0;i<I;++i)
        {
            x= rand()%(2*N);
            y= rand()%(2*N);
            if ((N-x)*(N-x)+(N-y)*(N-y)<=N*N) 
                sum[0]+=1;
        }

    end_t = clock();
    printf("\npi=%lf\n",(4.0)*(double)sum[0]/(I));
    printf("Normal: Gecen zaman = %.7f sn.\n",(double)(end_t - start_t) / CLOCKS_PER_SEC);

    return 1;
}