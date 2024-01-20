#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
void BadAlgorithm(int);
void GoodAlgorithm(int);

int main(){
		clock_t begin = clock();
    	BadAlgorithm(30000);
    	clock_t end = clock();
		printf("Time Spent Of Bad Algorithm : %lf\n",(double)(end - begin) / CLOCKS_PER_SEC);
		printf("\n---------\n");
		begin = clock();
		GoodAlgorithm(30000);
		end = clock(); 
		printf("Time Spent Of Good Algorithm : %lf\n",(double)(end - begin) / CLOCKS_PER_SEC);
    }
void BadAlgorithm(int N){                                   
    bool *doors=(bool *)malloc(N*sizeof(bool));
    
    int i;
    for(i=0;i<N;++i)       
        doors[i]=false;

    for(i=0;i<N;++i){
        int j;
        for(j=i;j<N;++j)
            if((j+1)%(i+1)==0)
                doors[j]=!doors[j];
    }
    int count=0;
    for(i=0;i<N;++i)
	    if(doors[i]){
			//printf("%d\n",i+1);
			count+=1;
		}
	printf("number of Open Door is %d\n",count);
	
}
void GoodAlgorithm(int N){
	int i,j=1;
	for(i=1;i<N+1;i+=j){
		//printf("%d\n",i);
		j+=2;
	}
	printf("number of Open Door is %d\n",(int)(sqrt(N)));
}
