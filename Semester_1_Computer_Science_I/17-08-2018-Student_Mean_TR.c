#include <stdio.h>
int main(){
	int o[10],a,top,s=0;
	for(int i=1;i<11;i++){
		printf("%d nolu ogrencinin notunu giriniz.",i); scanf("%d",&a);
		o[i]=a;
		top=top+a;
		s++;
	}
	printf("girdiginiz ogrencilerin ortalamasi : %.2f",(float)top/(float)s);
	
	
}