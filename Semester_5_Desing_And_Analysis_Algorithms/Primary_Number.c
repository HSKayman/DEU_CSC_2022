#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool Is_Primer(int x){
    if(x>2){
        if(x%2==0)
            return false;
        for(unsigned i=3;i<=sqrt(x);i+=2)
            if(x%i==0)
                return false;
    }else if(x==2)
        return true;
    else
        return false;
    return true;   
}
int main(){
    int i;
    for(i=2;i<100;++i)
        printf("%d-->%s\n",i,Is_Primer(i)?"P":"NP");
}