#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#include<time.h>
#include<omp.h>
int main(int argc, char **argv){

    uint32_t i,n=16, number_t, *series,*sum,items,sumall=0;

    if (argc != 3){
        printf("Missing Arg!\n");
        return 0;
    }
    number_t=atoi(argv[1]);
    n=atoi(argv[2]);
    //omp_set_dynamic(0);
    omp_set_num_threads(number_t); // thread sayısını önceden belirlemek isterseniz, bu satırı kullanabilirsiniz
    number_t=omp_get_max_threads();
    series=(uint32_t*)malloc(n*sizeof(uint32_t));
    sum=(uint32_t*)malloc(number_t*sizeof(uint32_t));
    srand(time(0));

    for (i=0;i<n;++i)
        series[i]=rand()%100;
	
	//printf("\n");
    //for (i = 0; i < n; i++)
    //    printf("%u ", series[i]);
    //printf("\n");

    //Manuel Parallel Sum Function
    sum=(uint32_t*)calloc(number_t,sizeof(uint32_t));
    items=n/number_t;
    double wtime = -1*omp_get_wtime();
	#pragma omp parallel private(i) shared(sum,series,sumall,number_t)
	{
		uint32_t tid=omp_get_thread_num();
        
        uint32_t start=tid*items;
        uint32_t end=start+items;
        if(tid==number_t-1)
            end=n;

        for(i=start;i<end;++i)
            sum[tid]+=series[i];
        #pragma omp barrier
        #pragma omp single
        {
            for(i=0;i<number_t;++i)
                sumall+=sum[i];
        }
	}
    
    wtime+=omp_get_wtime();
    printf("Manuel %u Threads:\t Sum:%u ,Time: %lf\n",number_t,sumall,wtime);
    
    //Auto Parallel Sum Function
    sumall=0;
    wtime = -1*omp_get_wtime();
    #pragma omp parallel for reduction(+:sumall)
        for(i=0;i<n;++i)
            sumall+=series[i];
    wtime+=omp_get_wtime();
    printf("Auto %u Threads:\t\t Sum:%u ,Time: %lf\n",number_t,sumall,wtime);
    
    sumall=0;
    clock_t times = -1*clock();
    for(i=0;i<n;++i)
        sumall+=series[i];
      
    times+=clock();
    printf("1 Thread:\t\t Sum:%u ,Time: %lf\n",sumall,(double)times/CLOCKS_PER_SEC);
    
    return 0;
}
