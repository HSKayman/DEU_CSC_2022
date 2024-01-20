int main(){
	int a,at=0,i;
	printf("lutfen bir sayi giriniz"); scanf("%d",&a);
	for(i=3;i<=a;i++){
		int b=2,f=0;
		while(b<i){
			if(i%b==0){
				f=1;
			}
				b++;
			}
				
	if(f==0){
	printf(" %d\n",i);
 	at= at+i;
	
		
}
}
printf("\nGirdiginiz sayiya kadar olan asal sayilarin toplami:%d",at);
}