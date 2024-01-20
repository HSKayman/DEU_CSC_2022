#include<stdio.h>
unsigned gcd(unsigned a,unsigned b){
    if(!(a%b))
        return b;
    return gcd(b,a%b);
}
int main(){
    printf("%u",gcd(35,25));
}