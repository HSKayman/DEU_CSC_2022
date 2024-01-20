#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int r=3,lim=2;//r and limit
    double *random_number=(double *)calloc(r,sizeof(double));
    int i,sum=0;
    srand(time(0));
    for(i=0;i<r;++i){
        random_number[i]=rand()%100;
        sum+=random_number[i];
    }
    for (i=0;i<r;++i){
        random_number[i]/=sum/lim; // reverse
        printf("%d) %lf\n",i,random_number[i]);
    }
}