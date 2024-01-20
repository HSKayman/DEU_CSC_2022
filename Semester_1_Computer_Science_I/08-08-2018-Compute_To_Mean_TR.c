#include<stdio.h>
#include<math.h>
int main(){
	 printf("-1 basana kadar ortalama islemi devam edecektir. ");
	 int n = 0;
	 while(g!=-1){
	 	scanf("%d",&g);
		n++;
		t=t+g;
	 	printf("\nSuanlik Ortalama :%.2f\nGirdiginiz sayilarin sayis:%d \nGirdiginiz sayilarin toplami: %.1f \n",t/n,n,t);
	 }
	 printf("\nSon An Ortalama :%.2f",t/n);
	 int k=0;
	 for(int n=1; g!=-1;n++){
	 	scanf("%d",&g);
		k++;
		if(g!=-1){
		
			t=t+g;
	 	printf("\nSuanlik Ortalama :%.2f\nGirdiginiz sayilarin sayis:%d \nGirdiginiz sayilarin toplami: %.1f \n",t/n,n,t);}
	 }
	 printf("\nSon An Ortalama :%.2f",t/(k-1));
	 }