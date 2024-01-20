#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ogrenci{
	char ad[20];
	char soyad[20];
	char bolum[30];
	int no;
	int ort;
}ogr,ogr2;
struct kitaplar{
	char ad[20];
	char yazar[20];
	int fiyat;
}ktp1={"Alakali","AsdasAsdas",12},
ktp2={"Alakadsafg","AsdasAsdas",122}
;
int main(){
	strcpy(ogr.ad,"Meltem");
	strcpy(ogr.soyad,"Aydin");
	strcpy(ogr.bolum,"Bilgisayar_sistemleri");
	ogr.no=12345;
	ogr.ort=78;
	
	strcpy(ogr2.ad,"Ayse");
	strcpy(ogr2.soyad,"Mahlize");
	strcpy(ogr2.bolum,"Bilgisayar_bilimcisi");
	ogr2.no=1234455;
	ogr2.ort=89;
	
	printf("Adi    	  :%s\n",ogr.ad);
	printf("Soyadi    :%s\n",ogr.soyad);
	printf("Bolum     :%s\n",ogr.bolum);
	printf("No        :%d\n",ogr.no);
	printf("Ortalama  :%d\n",ogr.ort);
	printf("\n\nAdi    	  :%s\n",ogr2.ad);
	printf("Soyadi    :%s\n",ogr2.soyad);
	printf("Bolum     :%s\n",ogr2.bolum);
	printf("No        :%d\n",ogr2.no);
	printf("Ortalama  :%d\n",ogr2.ort);
	printf("Adi    	  :%s\n",ktp1.ad);
	printf("yazar     :%s\n",ktp1.yazar);
	printf("fiyat     :%d\n",ktp1.fiyat);
	printf("Adi    	  :%s\n",ktp2.ad);
	printf("yazar     :%s\n",ktp2.yazar);
	printf("fiyat     :%d\n",ktp2.fiyat);	
	int a=5, *ap;
	float b=3.14,*bp;
	double c=3.1415285, *cp;
	char d ='a',*dp;
	int say[5]={1,2,3,4,5};
	int *sayp;
	ap=&a;
	bp=&b;
	cp=&c;
	dp=&d;
	sayp=&say[0];
	
	printf("%p adresindeki intin degeri %d dir.\n",ap,*ap);
	printf("%p adresindeki floatin degeri %f dir.\n",bp,*bp);
	printf("%p adresindeki doublenin degeri %lf dir.\n",cp,*cp);
	printf("%p adresindeki charin degeri %c dir.\n",dp,*dp);
	printf("%p adresindeki dizinin degeri %d dir.\n",sayp,*sayp);
	printf("%p adresindeki dizinin degeri %d dir.\n",sayp,*(sayp+1));
	printf("%p adresindeki dizinin degeri %d dir.\n",sayp,*(sayp+2));
	printf("%p adresindeki dizinin degeri %d dir.\n",sayp,*(sayp+3));
	printf("%p adresindeki dizinin degeri %d dir.\n",sayp,*(sayp+4));
				
} 