#include<stdio.h>
int main(){
	int s1,s2,i,c=0,d=0,a,b;
	printf("Lutfen iki sayi giriniz : "); scanf("%d%d",&s1,&s2);
	if(s1>s2){
		a=s1;
		b=s2;
	}
	else{
		a=s2;
		b=s1;
	}
	for(i=b;i<=a;i++){
		if(i%2==0)
		c=c+i;
		else
		d=d+i;	
		}
	
	printf("Girdiginiz sayilarin arasindaki tek sayilarin toplami :%d\nGirdiginiz sayilarin arasindaki cift sayilarin toplami :%d",d,c);
	
	
}