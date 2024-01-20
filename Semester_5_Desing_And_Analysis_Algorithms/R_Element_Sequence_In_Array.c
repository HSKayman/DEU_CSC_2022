#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Binary_To_Decimal(int array[],int start,int dim){
    int i,result=0;
    for(i=start;i<start+dim;++i)
        result+=pow(2,(start+dim-1)-i)*array[i]; 
    return result;
}
int main(){
    int size=22,r=3;//size and r
    int Dataset[]={0,1,1,0,0,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,1,1};//input
    int i,*Result=(int *)calloc(pow(2,r),sizeof(int));
    
    for(i=0;i<=size-r;++i)
        ++Result[Binary_To_Decimal(Dataset,i,3)];
    for(i=0;i<pow(2,r);++i)
        printf("%d) %d\n",i,Result[i]);
    
}