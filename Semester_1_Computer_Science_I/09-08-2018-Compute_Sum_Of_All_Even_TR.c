int main(){
	int a,b,c,d=0;
	printf("Lutfen iki sayi giriniz :"); scanf("%d%d",&a,&b);
	if(a<b){
	for(int i=a;i<=b;i++){
		if(i%2==0){
			d=d+i;
			
		}
	}
}
else{
	for(int i=b;i<=a;i++){
		if(i%2==0){
			d=d+i;
			
		}
	}
}
printf("\n%d",d);
}