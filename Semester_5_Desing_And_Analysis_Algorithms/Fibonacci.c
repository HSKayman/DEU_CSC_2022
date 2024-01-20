#include<stdio.h>
#include<math.h>
#include <time.h>
unsigned fibrec(unsigned);//Recursive
unsigned fibstac();//Stack
unsigned fibform(unsigned);//Formula
int main(){
    unsigned i,n=40;
	
	//For Recursive
	clock_t start=clock();
	for(i=1;i<n;++i){
		printf("f(%u)=%u \n",i,fibrec(i));
	}
	clock_t difference = (clock() - start)*1000/CLOCKS_PER_SEC;
	printf("\n\n %ld ms \n\n",difference);
	
	///For Static
	start=clock();
	printf("f(1)=1 \n");
	printf("f(2)=1 \n");
	for(i=3;i<n;++i){
		printf("f(%u)=%u \n",i,fibstac(i));
	}
	difference = (clock() - start)*1000/CLOCKS_PER_SEC;
	printf("\n\n %ld ms \n\n",difference);
	
	//For Formula
	start=clock();
	for(i=1;i<n;++i){
		printf("f(%u)=%u \n",i,fibform(i));
	}
	difference = (clock() - start)*1000/CLOCKS_PER_SEC;
	printf("\n\n %ld ms \n\n",difference);
}
unsigned fibrec(unsigned x){
    if(x<3){
        return 1;
    }
    return fibrec(x-1)+fibrec(x-2);
    
}
unsigned fibstac(unsigned x){
    static unsigned a=1,b=1;
	unsigned c=a+b;
	a=b;
	b=c;
	return c;
} 
unsigned fibform(unsigned x){
	return (unsigned)((pow((1+sqrt(5))/2,x)-pow((1-sqrt(5))/2,x))/(sqrt(5)));
}
