#include<stdio.h>
void Base(int x, int base){//reverse
    
    if(x<10){
        printf("%d",x);
    }else if(x<base){
        printf("%c",'A'+(x-10));
    }else{
        if((x%base)<10){
        printf("%d",x%base);
        }else{
            printf("%c",'A'+(x-10));
        }
        return Base(x/base,base);
    }
}
int main(){
    Base(18,16);
}