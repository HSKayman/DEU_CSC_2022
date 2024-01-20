#include<stdio.h>
int main(){
	int a,i=0,min,result=1;
	while(i<10){
		printf("Lutfen %d. kamyonun Aldigi Yolu Giriniz :",i+1);
		scanf("%d",&a);
		if(a<100)
			a*=5000;
		else if(a<200)
			a*=6000;
		else if(a<601)
			a*=7000;
		else
			a*=9000;
		if(i==0)
			min=a;
		printf("Alacagi Ucret %d\n\n",a);
		if(min>a){
			min=a;
			result=i+1;
		}
		i++;
	}
	printf("%d. araba en az para almis",result);
}