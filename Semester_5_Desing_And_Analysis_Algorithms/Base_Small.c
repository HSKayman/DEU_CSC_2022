#include<stdio.h>
void Base(int x,int base){//base<10
    if(x<base)
        printf("%d",x);
    else{
        printf("%d",x%base);
        Base(x/base,base);
    }    
}

int main(){
    Base(13,2);
}
