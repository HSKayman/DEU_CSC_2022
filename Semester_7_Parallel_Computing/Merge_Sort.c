//2017280030 numaram geregi merge-sort algoritmasini kullandim ve bottom-up implementiyle odevimi yaptim
//merge-sort algoritmasini kullanirken parallellestirmeyi stepSize ayni iken butun arrayi paylastirdim
//boylelikle stepSize arrayin boyutuna gecincege kadar sanki recursive yapilmis gibi dynamic kodladim
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
#include<stdint.h>
#include<stdbool.h>
void print(uint32_t*, uint32_t );
void merge(uint32_t*, uint32_t*, uint32_t, uint32_t, uint32_t);
int main(){
    
    uint32_t i, size, *series, *temp;
    uint8_t threadNum;
    

    //File read process
    FILE *fp;
    fp=fopen("girdi.txt", "r");
    fscanf(fp,"%u",&threadNum);
    fscanf(fp,"%u",&size);

    //dynamic memory allocation process
    //omp_set_dynamic(0);
    omp_set_num_threads(threadNum);
    series=(uint32_t*)malloc(size*sizeof(uint32_t));
    temp=(uint32_t*)malloc(size*sizeof(uint32_t));

    //read data
    for(i=0;i<size;++i)
        fscanf(fp,"%u",&series[i]);
    fclose(fp);


	//print(series,size); 
    
    //wall clock = end-start (starting must -1 times)
    double wtime= -1*omp_get_wtime();

    //Merge-Sort Algorithm
    uint32_t stepSplit=1;
    while(stepSplit<size){
        #pragma omp parallel for schedule(dynamic)
        for(i=stepSplit;i<size; i+=2*stepSplit)
            merge(series,temp,i-stepSplit,i,i+stepSplit>size ? size : i+stepSplit);
        stepSplit*=2;
    }
  
    //wall clock = end-start (ending must 1 time)
    wtime+=omp_get_wtime();
    printf("%.2lf",wtime);

    //print(series,size); 

    //write data
    fp = fopen("cikti.txt","w");
    fprintf(fp,"%u\n",threadNum);
    fprintf(fp,"%u\n",size);

    for(i=0;i<size;++i)
        fprintf(fp,"%u\n",series[i]);
    fclose(fp);
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
