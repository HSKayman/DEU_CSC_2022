#include<stdio.h>
long long unsigned Fac(int n){
    if(n==1)
        return 1;
    return n*(Fac(n-1));
}
double Sin(double x,int n){
    int limit=4*(n/2+n%2)-1;
    double positive=1;
    double negative=1;
    double fac=1/(double)Fac(limit);
    double x_e=x*x*x*x;
    while(limit>0){
        negative=x_e*negative+fac;
        fac*=limit*(limit-1);
        positive=x_e*positive+fac;
        limit-=2;
        fac*=limit*(limit-1);
        limit-=2;
    }
    return positive-negative;
}

int main(){
    printf("%lf",Sin(1.0,10));
    
}