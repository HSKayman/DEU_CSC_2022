#include<stdio.h>
#include<omp.h>

int main(){

    omp_set_dynamic(0);
    omp_set_num_threads(5);

    #pragma omp parallel //num_threads (5)
    {
        int tid = omp_get_thread_num();
        int tsay = omp_get_num_threads();

        printf("Hellow World! By %d T Of %d\n",tid,tsay);
    }
     #pragma omp parallel //num_threads (10)
    {
        int tid = omp_get_thread_num();
        int tsay = omp_get_num_threads();

        printf("!!Hellow World! By %d T Of %d\n",tid,tsay);
    }
    return 0;
}