#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
#include<stdint.h>
#include<stdbool.h>
void print(uint32_t*, uint32_t );
void merge(uint32_t*, uint32_t*, uint32_t, uint32_t, uint32_t);
int main(int argc, char **argv){
    
    uint32_t i, size, threadNum, *series, *temp;
    if (argc != 3){
        printf("Missed Arg\n");
        return 0;
    }
    size=atoi(argv[1]);
    threadNum=atoi(argv[2]);
    
    //omp_set_dynamic(0);
    omp_set_num_threads(threadNum);
    series=(uint32_t*)malloc(size*sizeof(uint32_t));
    temp=(uint32_t*)malloc(size*sizeof(uint32_t));

    srand(time(0));
    for(i=0;i<size;++i)
        series[i]=((40*rand())-rand()%40)%1000000;

    FILE *fp = fopen("girdi.txt","w");
    fprintf(fp,"%u\n",threadNum);
    fprintf(fp,"%u\n",size);

    for(i=0;i<size;++i)
        fprintf(fp,"%u\n",series[i]);
    fclose(fp);

	//print(series,size);
    double wtime = -1*omp_get_wtime();
    uint32_t stepSplit=1;
    while(stepSplit<size){
        #pragma omp parallel for schedule(guided, 2)
        for(i=stepSplit;i<size; i+=2*stepSplit)
            merge(series,temp,i-stepSplit,i,i+stepSplit>size ? size : i+stepSplit);
        stepSplit*=2;
    }
  
    wtime+=omp_get_wtime();
    printf("Parallel Time: %lf",wtime);


    fp = fopen("cikti.txt","w");
    fprintf(fp,"%u\n",threadNum);
    fprintf(fp,"%u\n",size);

    for(i=0;i<size;++i)
        fprintf(fp,"%u\n",series[i]);
    fclose(fp);
    
    /*
    //print(series,size);
    for(i=0;i<size;++i)
        series[i]=rand()%1000000;
    //print(series,size);

    clock_t times = -1*clock();
    stepSplit=1;
    while(stepSplit<size){
        for(i=stepSplit;i<size; i+=2*stepSplit){
            uint32_t limit=i+stepSplit>size ? size : i+stepSplit;
            //printf("\n[%u-%u-%u]\n",i-stepSplit,i,limit);
            merge(series,temp,i-stepSplit,i,limit);
        }
        stepSplit*=2;
    }
    times+=clock();
    printf("\nSerial Time: %lf",(double)times/CLOCKS_PER_SEC);
    //print(series,size);
    */

    return 0;
}
void merge(uint32_t *series, uint32_t *temp, uint32_t left, uint32_t mid, uint32_t right){
    uint32_t i=left, j=mid, k=left;
    while(i<mid||j<right){
        if(i<mid&&j<right){
            //printf("%u\n",omp_get_thread_num()) ;
            if(series[i]<series[j]){
                temp[k]=series[i];
                ++k;
                ++i;
            }else{
                temp[k]=series[j];
                ++k;
                ++j;
            }
        }else if(i==mid){
            temp[k]=series[j]; 
            ++k;
            ++j;
        }else if(j==right){
            temp[k]=series[i]; 
                ++k;
                ++i;
        }
    }
    for (i=left;i<right;++i)
        series[i]=temp[i];
}


void print(uint32_t *series, uint32_t size){
    printf("\n");
    for(uint32_t i=0;i<size;++i)
        printf("%u ",series[i]);
    printf("\n"); 
}



