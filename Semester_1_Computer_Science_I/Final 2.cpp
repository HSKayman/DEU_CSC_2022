#include<stdio.h>
int power(int x,int y);

int main(){ 
	int b;
	 scanf("%d",&b);
	for(int a=1;a<=b;a++){
		int i=0, a1=a;
		while(a1!=0){
			a1=a1/10;
			i++;
			} 
			a1=a;
		int a2,count=0,value[i+1];
		while(i>0){
			a2=a1/power(10,i-1);
			value[count]=a2;
			count++;
			a1=a1-a2*power(10,i-1);
			i--;
		}
		a2=0;
		for(int i=0;i<count;i++){
			a2=a2+power(value[i],count);
		}
		if(a2==a){
			printf("%d\n",a2);
		}
		}
	}
	
int power(int x,int y){
		int sum=1;
		if(y==0)	
			return 1;
		else{
			for(int i=0;i<y;i++){
				sum=sum*x;
			}
			return sum;
			}
			}
