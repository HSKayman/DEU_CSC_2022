#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>
#include<omp.h>
int main(int argc, char **argv){
    omp_set_num_threads(4); // thread sayısını önceden belirlemek isterseniz, bu satırı kullanabilirsiniz
    
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                for(int i=0;i<5;++i)
                    printf("Task1[%d] --> %u\n",i,omp_get_thread_num());
            }
            #pragma omp section
            {
                for(int i=0;i<5;++i)
                    printf("Task2[%d] --> %u\n",i,omp_get_thread_num());
            }
        }
    }
    printf("\n---\n");
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            {
                for(int i=0;i<5;++i)
                    printf("Task1[%d] --> %u\n",i,omp_get_thread_num());
            }
            #pragma omp task
            {
                for(int i=0;i<5;++i)
                    printf("Task2[%d] --> %u\n",i,omp_get_thread_num());
            }
            #pragma omp taskwait
        }
    }
    printf("\n---\n");
    #pragma omp parallel
    {
        if (omp_get_thread_num()%2==0){
                #pragma omp for
                for(int i=0;i<5;++i)
                    printf("Task1[%d] --> %u\n",i,omp_get_thread_num());
            }else{
                #pragma omp for
                for(int j=0;j<5;++j)
                    printf("Task2[%d] --> %u\n",j,omp_get_thread_num());
            }
            #pragma omp barrier
        
    }

}