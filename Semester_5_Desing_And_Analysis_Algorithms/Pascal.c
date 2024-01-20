#include<stdio.h>

int cnr(int n,int r){
    if(r==0||r==n)
        return 1;
    else
        return cnr(n-1,r-1)+cnr(n-1,r);
}
int main(){
    printf("%d",cnr(6,3));
}