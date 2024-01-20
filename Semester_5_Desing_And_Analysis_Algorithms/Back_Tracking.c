#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
void BackTracking(unsigned size);
int main(){
    int i;
    //for(i=1;i<6;++i)
        printf("\n\n--------------\n\n");
        BackTracking(2);
    

}
bool Control(unsigned *array,unsigned pivot){
    int i;
    for(i=1;i<pivot;++i)
        //if(abs(array[pivot]-array[i])==abs(pivot-i)||array[pivot]==array[i])//For Queen
        //    return false;
        
        if(array[pivot]==array[i])// For Rook// For Combination pivot>=i//combination
            return false;
        
        //if(abs(array[pivot]-array[i])==abs(pivot-i))//For Bishop
        //    return false;
    return true;
}//[0,0,0]
void BackTracking(unsigned size){
    unsigned *array=(unsigned *)calloc(size+1,sizeof(unsigned));
    int pivot=1,count=0;
    while(pivot>0){
        ++array[pivot];
        while(array[pivot]<size+1&&!Control(array,pivot))//Search For Avaliable
            ++array[pivot];
        if(array[pivot]<size+1){//Out of i Range
            if(pivot==size){////////////////////Out Of j Range Sound Like Finish One Element Of All Element
                printf("%3u) ",++count);
                int i;
                for(i=1;i<size+1;++i)//////// (n,r) : from i=1 to r+1'e 
                    printf("%4u ",array[i]);
                printf("\n");
            }
            else //Search For Other Value
                array[++pivot]=0;
        }
        else // Search For Other i Diffirent Way
            --pivot;
    }
    free(array);
}