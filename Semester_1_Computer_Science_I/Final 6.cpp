#include<stdio.h>
int main(){
	printf("Lutfen Gireceginiz evin kordinatsal olarak merkezlerini giriniz.\n\n");
	int i,j;
	int A[10][2];
	for(i=0;i<10;i++)
	{
		printf("\n%d. Evin x,y olmak suretiyle kordinatlari giriniz =>",i+1);
		scanf("%d %d",&A[i][0],&A[i][1]);
		
	}
	int max=A[0][0],min=A[0][0],max2=A[0][1],min2=A[0][1];
	int kategori1[10],kategori[10];
	for(i=0;i<10;i++)
	{ 
		if(max<A[i][0])
			max=A[i][0];//x1
		if(min>A[i][0])
			min=A[i][0];//x2
		if(max2<A[i][1])
			max2=A[i][1];//y1
		if(min2>A[i][1])
			min2=A[i][1];//y2
	}
	max++;min--;max2++;min2--;
	int say=0;
	float denk=float(max2-min2)/float(max-min);
	for(i=0;i<10;i++)
	{
		if(float(max2-min2)*((float)A[i][0]-min)>float(max-min)*(((float)A[i][1]-min2)))
		{
			kategori[say++]=i;
		}
	}
	int sum1=0.00,sum2=0.00,summer1=0.00,summer2=0.00;
	for(i=0;i<10;i++)
	{
		int fsf=0;
		for(j=0;j<say;j++)
		{
			if(i==kategori[j])
			{
				sum1+=A[i][0];
				sum2+=A[i][1];
				fsf=1;
				break;
			}
		}
		if(fsf==0)
		{
			summer1+=A[i][0];
			summer2+=A[i][1];
		}
	}
	
	printf("Dogal Gaz Tesisi %.3f,%.3f ve %.3f,%.3f ye konulmasi en verimlisidir.",(float)sum1/say,(float)sum2/say,(float)summer1/(10-say),(float)summer2/(10-say));
}
