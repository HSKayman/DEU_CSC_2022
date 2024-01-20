#include<stdio.h>
void mark(int vize,int final){ 

float ort=(float)vize*0.4+(float)final*0.6;
if(ort>=90)
printf("Ortalama : %.2f - 'AA'",ort);
else if(ort>=70)
printf("Ortalama : %.2f - 'BB'",ort);
else if(ort>=50)
printf("Ortalama : %.2f - 'CC'",ort);
else if(ort>=30)
printf("Ortalama : %.2f - 'DD'",ort);
else
printf("Ortalama : %.2f - 'FF'",ort);
}
int main(){
	q1: int vize,final;
	printf("\nVize Notunuz :"); scanf("%d",&vize);
	printf("\nFinal Notunuz :"); scanf("%d",&final);
	if(vize>100 || vize<0 || final<0 || final>100){
		printf("Yanlis Sayi Girisinde Bulundunuz. \n Lutfen Tekrar Deneyiniz.");
		goto q1;
	}
	mark(vize,final);
}
