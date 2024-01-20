#include<stdio.h>
#include<math.h>
#define Q 100000
int main()
{
	int al,bilo; //girdi degisken tanimi
	printf("Sayi Giriniz :"); //ekrana yazdir
	scanf("%d",&al);//girdiyi degiskene kaydetme
	int A[Q],B[Q],j;//sirali A dizisi ve B dizisi
	for(int i=2;i<=al;i++)//A ve B dizisine sayilari kaydetme
	{
		A[i]=i;
		B[i]=-1;
		printf("%3d ",A[i]);	//sayilarin ilk halini ekrana yazdirma
	}
	int f; //degiskenin icine kaydetmek icin gerekli degisken
	for(int i=2;i<=sqrt(al);i++) //kambur algoritmasi icin gerek karekok dongusu
	{
		int flag=0;
		if(A[i]!=-1) //ilk bulunan asallarin katlarini ele almasin diye icine kaydettigim -1 isareti
		{
			B[i]=A[i]; //A kumesinden B kumesine gecis
			j=A[i]; //hata olmasin diye a kumesinden gecici degiskene gecis
			f=i*i; // dizi numarasini kaydetmem icin gerekli degiskene sayi atama ve karesinden baslatma
			flag=1;//bosa asama olmasin diye bayrak kullaniyorum
			while(f<=al) //girdigimiz sayiya kadar olan dongu
			{
				if(A[f]%j==0) //A dizisinde her hangi bir sayi asala bolunuyorsa
				{
					A[f]=-1; //o sayiyi isaretle
				}
			f++;//dizinin icindeki numarayi arttir boylelikle dongu sagla
			}
		}
		if(flag==1)
		{
			printf("\n************************************************************************************************************************\n************************************************************************************************************************\n\n\n");
			//goruntu icin estettik
			printf("\n %d.Asama==> S.A.S==(%d)..",++bilo,j);
			//asama adimlarinin ismi
			for(int j=2;j<=al;j++)//ekrana yazdirma dongusu
			{
				if(A[j]==-1)//eger isaretliyse o sayi -- koy
				{
					printf("-- ");	
				}
				else // degilse ekrana yazdir
				{
					printf("%3d ",A[j]);
				}
			}
		}
}}
