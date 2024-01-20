#include<stdio.h>
int main(){
	int a[16]={0},i,sum=0,result;
	float max=0.0;
	for(i=0;i<16;i++){
		printf("Lutfen %d. degeri girin :",i+1);
		scanf("%d",&a[i]);
		if(i%4!=3)
			sum+=a[i];
		else{
			sum+=a[i];
			if(max<sum){
				max=sum;
				result=i;
			}
			printf("Bu Son Dortlu Grubun Ortalamasi %.4f\n",sum/4.00); 
			sum=0;
	}	
}
	printf("En buyuk ortalamali grup %d",(result+1)/4);
}