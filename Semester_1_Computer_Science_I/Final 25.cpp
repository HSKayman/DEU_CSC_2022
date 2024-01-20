#include<stdio.h>
int main(){
	int i,a[4][2];
	for(i=0;i<4;i++)
	{
	printf("%d.Noktanin kordinatlarini giriniz::>(x)(y)",i+1); scanf("%d%d",&a[i][0],&a[i][1]);
	}
	int a1[6]={0};		
	for(i=0;i<2;i++)//////////////////////////////////////////////////////////////////
	a1[0]+=(a[0][i]-a[1][i])*(a[0][i]-a[1][i]);//0-1
	for(i=0;i<2;i++)
	a1[1]+=(a[2][i]-a[3][i])*(a[2][i]-a[3][i]);//2-3
	for(i=0;i<2;i++)//////////////////////////////////////////////////////////////////
	a1[2]+=(a[0][i]-a[2][i])*(a[0][i]-a[2][i]);//0-2
	for(i=0;i<2;i++)
	a1[3]+=(a[1][i]-a[3][i])*(a[1][i]-a[3][i]);//1-3
	for(i=0;i<2;i++)/////////////////////////////////////////////////////////////////
	a1[4]+=(a[0][i]-a[3][i])*(a[0][i]-a[3][i]);//0-3
	for(i=0;i<2;i++)
	a1[5]+=(a[1][i]-a[2][i])*(a[1][i]-a[2][i]);//1-2
	int fas=0;
	for(i=0;i<5;i+=2)
	{
		if(a1[i]!=a1[i+1])
		{
			fas=1;
		}
	}
	if(fas==0)
	{
		printf("Girdiginiz Noktalar Dikdortgen olmaya uygundur.");
	}else
		printf("Girdiginiz Noktalar Dikdortgen olmaya uygun degildir.");
	
}
