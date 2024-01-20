#include<stdio.h>
int main(){
	printf("Lutfen Gireceginiz evin kordinatsal olarak merkezlerini giriniz.\n\n");
	int i;
	int A[10][2],sum=0,sakiz=0;
	for(i=0;i<10;i++)
	{
		printf("\n%d. Evin x,y olmak suretiyle kordinatlari giriniz =>",i+1); scanf("%d %d",&A[i][0],&A[i][1]);
		sum+=A[i][0]; sakiz+=A[i][1];
	}
	printf("Dogal Gaz Tesisi %.3f,%.3f ye konulmasi en verimlisidir.",(float)sum/10.00,(float)sakiz/10.00);
}
