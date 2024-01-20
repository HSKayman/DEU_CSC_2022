#include<stdio.h>
int main(){
int a=2,r;
	 scanf("%d",&b);
	 while(a<=b-1){
			
		 if(b%a==0){
		 	r=1;
		 	break;  
		 }
		 else{
		 	r=2;
		 }
		 
		a++;
	 }
	 if(r==1){
	 	printf("Girmis Oldugunuz Sayi Asal Degildir. Sayi Bu:%d\t%d",b,a);
	 }
	 else if(r==2){
	 	printf("Girmis oldugunuz Sayi Asaldir. Sayi Bu:%d\t%d\t%d",b,a,r);
	 }
	
}
