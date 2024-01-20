#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef union{
	float kilo;
	int adet;


}birim;
typedef struct{
	int x;
	char y[20];
	birim miktar;
}Kimlik;
void qwert(Kimlik *p){
	int i;
	printf("\n%d %s %d\n",p[1].x,p[1].y,p[1].miktar.adet);
	printf("%d %s %f",p[0].x,p[0].y,p[0].miktar.kilo);

}
int main(){
	Kimlik A[2];
	Kimlik *s;
	s=A;
	A[0].x=18;
	strcpy(A[0].y,"Un");
	A[1].x=4;
	strcpy(A[1].y,"caklit");
	A[0].miktar.kilo=1.00;
	A[1].miktar.adet=1;
	qwert(s);
}