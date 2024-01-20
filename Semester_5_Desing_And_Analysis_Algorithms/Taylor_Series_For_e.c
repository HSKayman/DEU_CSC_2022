#include<stdio.h>
double Series(unsigned long long x,unsigned long long n){
    unsigned long long multiply=1,fac=1,i,iterate_x=x;
    double result=1.0;
    for(i=1;i<n;++i){
        result+=(double)iterate_x/(double)fac;
        fac*=(i+1);
        iterate_x*=x;
    }
    return result;
}
int main(){
    for(int i=1;i<30;++i){
        printf("Step-%d)  e:%.16lf\n",i,Series(1,i));
    }
}