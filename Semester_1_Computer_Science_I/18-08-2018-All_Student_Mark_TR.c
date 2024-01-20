#include<stdio.h>
int main(){
	int o[10],a,AAnotu=0,BBnotu=0,CCnotu=0,DDnotu=0,FFnotu=0,f[10],os[10];
	for(int i=0;i<10;i++){
		printf("%d. ogrencinin vize notu :",i+1); scanf("%d",&o[i]);
		printf("%d. ogrencinin final notu :",i+1); scanf("%d",&f[i]);
		os[i]=(o[i]*4+f[i]*6)/10;
		if(os[i]>=90)
			AAnotu++;
		else if(os[i]>=70)
			BBnotu++;
		else if(os[i]>=50)
			CCnotu++;
		else if(os[i]>=30)
			DDnotu++;
		else
			FFnotu++;
	}
	 printf("\n -------------------------------------------\nAA alan sayisi :%d\n BB alan sayisi :%d\nCC alan sayisi :%d\nDD alan sayisi :%d\nFF alan sayisi :%d",AAnotu,BBnotu,CCnotu,DDnotu,FFnotu); 

}
