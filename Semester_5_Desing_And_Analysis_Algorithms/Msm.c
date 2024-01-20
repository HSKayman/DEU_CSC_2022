#include<stdio.h>
unsigned gcd(unsigned a,unsigned b){
    if(!(a%b))
        return b;
    return gcd(b,a%b);
}
unsigned msm(unsigned a,unsigned b){
    return a*b/gcd(a,b);
}
int main(){
    printf("%u",msm(35,25));   
}