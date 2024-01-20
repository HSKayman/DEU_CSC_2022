
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>
#include<omp.h>
uint8_t calculate(double x0,double y0){
    double x=0,y=0;
    uint32_t iteration=0;
    while(x*x+y*y<=4 && iteration<1000){
        double x_temp=x*x-y*y+x0;
        y=2*x*y+y0;
        x=x_temp;
        ++iteration;
    }
    return iteration==1000 ? 1:0;
}

int main(int argc, char **argv){


    uint32_t j,i,n=16,number_t=4,**series;
    if (argc != 3){
        printf("Missing Arg!\n");
        return 0;
    }
    number_t=atoi(argv[1]);
    n=atoi(argv[2]);
    omp_set_num_threads(number_t); 
    number_t=omp_get_num_threads();
    
    series=(uint32_t**)calloc(4*n,sizeof(uint32_t*));
    for(i=0;i<4*n;++i)
        series[i]=(uint32_t*)calloc(4*n,sizeof(uint32_t));

    #pragma omp parallel for collapse(2) schedule(dynamic,4)
    for(i=0;i<4*n;++i)
        for(j=0;j<4*n;++j)
            series[i][j]=calculate(2-((double)(i+1)/n),-2+((double)(j+1)/n));


    for(i=0;i<4*n;++i){
        for(j=0;j<4*n;++j)
            printf("%s ",series[i][j]?"*":"");
        printf("\n");
        }
        

}