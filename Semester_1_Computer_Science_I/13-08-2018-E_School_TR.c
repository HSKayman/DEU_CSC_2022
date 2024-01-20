#include<stdio.h>
int main(){
	int a,i,top=0,e=0,k=100,j,s,s2;
	int o[99];
	for(i=0;a!=-1;i++){
	q34: printf("\n\nLutfen %d Ogrencinin Notunu giriniz (islemi bitirmek icin -1'e basiniz) :",i); scanf("%d",&a);
	for(j=0;j<i;j++){
		if(a==o[j] && a!=0 && a!=-1){
	printf("bu rakami daha onceden girdiniz tekrar deneyin ;"); 
	goto q34;
	}
	}
	if(a>e)
		e=a;
	if(a<k && a!=-1)
		k=a;
	switch(a!=-1){
		case 1:{	o[i]=a;
					top=a+top;
					printf("bu notu daha once girmemissiniz islem basarili");
			break;
		default: printf("islem basariyla bitirildi."); break;
		}}}
		int p=0;
		while(p<i-1){
		printf("\n%d ogrencinin notu: %d",p,o[p]);
		if(e==o[p]){
		s=p;}
		else if(k==o[p]){
		s2=p;	
		}
		p++;}
		printf("\n\n\n girdiginiz notlarin en buyugu:%d \t %d nolu ogrencinin \n girdiginiz notlarin en kucugu: %d \t %d nolu ogrencinin\n\n ortalama not :%d",e,s,k,s2,top/(i-1));
}