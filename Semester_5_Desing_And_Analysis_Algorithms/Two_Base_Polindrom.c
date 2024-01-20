#include<stdio.h>
#include<math.h>
int main(){
    int input=4;//Number of 2^base
    printf("%d",(int)(pow(2,(input/2)+input%2)));
}