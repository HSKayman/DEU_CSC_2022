#include<stdio.h>
int per(int x);
main(){
	int i;
	for(i=1;i<1000;i++){
		printf("%d=>%s\n",i,per(i) ? "Mukemmel" : "MukemmelDegil");
	}
}
int per(int x){
	int sum=0,i;
	for(i=1;i<=x/2;i++)
		if(x%i==0)
			sum+=i;
	if(x==sum)
		return 1;
	return 0;
}