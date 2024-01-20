#include<stdio.h>
void Honai(int x,char A,char B,char C){
    static unsigned a=1;
    if(x==1){
        printf("\n%u) %c-->%c",a++,A,C);
    }else{
        Honai(x-1,A,C,B);
        printf("\n%u) %c-->%c",a++,A,C);
        Honai(x-1,B,A,C);
    }
}
int main(){
    Honai(4,'A','B','C');
}