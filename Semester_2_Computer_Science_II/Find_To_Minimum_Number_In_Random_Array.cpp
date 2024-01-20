#include<stdlib.h>
#include<time.h>
#define sqrt(x) ((x)*(x))
#define cycl(r) 3.1415*sqrt(r)
void min(int x[],int y);
int main(){
	srand(time(0));
	int i,s=1000;
	int a[s];
	for(i=0;i<s;i++){
		a[i]=rand();
		printf("%d\t",a[i]);
	}
	printf("\n\n\n------------------\n\n\n");
	min(a,s);
}
void min(int x[],int y){
	int mini=x[0],i;
	for(i=1;i<y;i++)
		if(mini>x[i])
			mini=x[i];
	printf("\n\nMinimum Value :%d",mini);
}