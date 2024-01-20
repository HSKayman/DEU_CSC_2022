#include<stdio.h>
#include<math.h>
/*
C name	Value	Meaning
M_E	e	The base of natural logarithms, e.
M_LOG2E	log2e	The base 2 logarithm of e.
M_LOG10E	log10e	The base 2 logarithm of e.
M_LN2	ln 2	The natural logarithm of 2.
M_LN10	ln 10	The natural logarithm of 10.
M_PI	π	The circumference of a circle with diameter 1, π.
M_PI_2	π/2	Half of π.
M_PI_4	π/4	A quarter of π.
M_1_PI	1/π	The inverse of π.
M_2_PI	2/π	Twice the inverse of π.
M_2_SQRTPI	2/(√ π)	The inverse of the square root of π.
M_SQRT2	√2	The square root of 2.
M_SQRT1_2	1/(√2)	The inverse of the square root of 2.
HUGE		The maximum value of a single-precision floating-point number.
MAXFLOAT		The maximum value of a non-infinite single-precision floating-point number.
HUGE_VAL
*/
/*REGULAFALSI VE BISECTON ICIN ORNEK SORU
2*pow(x,3)-2.5*x-5 
x=1,y=1
*/
/*NEWTONRHAPSON ICIN ORNEK SORU
3*x*x+12*x+7
x=4,y=-2
*/
/*BASIT ITERASYON ICIN ORNEK SORU
x*x*x-x-3
x=1.5,y=2
*/
long double DifforNR(long double x){//Double Turev Alma
	return 2*pow(M_E,2*x)+1;  //###############################################################################################
}
long double func(long double x){//Fonsiyonun Kendisi
	return pow(x,x)-2;//###########################################################################################
}
long double RegulaFalsi(long double x,long double y){//Regula-Falsi Iterasyon Formulu
	return (x*func(y)-y*func(x))/(long double)(func(y)-func(x));
}
long double BiSection(long double x,long double y){//BiSection Iterasyon Formulu
	return (x+y)/(long double)2;
}
long double Diff(long double x){//Turev Alma Formulu
	long double h=pow(10,-16);
	return(func(x+h)-func(x))/h;
}
long double NewtonRhapson(long double x){//Newton-Rhapson Iterasyon Formulu
	return x-(func(x)/DifforNR(x));
}
long double AloneXfunc(long double x){//X'i Cekilmis
	return x; //###############################################################################################
}
long double BasicIteration(long double x){//Basit Iterasyon Formulu
	return AloneXfunc(x);
}
long double DifforIT(long double x){//Basit Iterasyon Icin Turev Alma
	long double h=pow(10,-31);
	return(AloneXfunc(x+h)-AloneXfunc(x))/h;
}
/*long double DifforNR(long double x){//Double Turev Alma
	return 2*pow(M_E,2*x)+1;  //###############################################################################################
}*/
int main(){
	long double x=1,y=2,limit=pow(10,-31);//x:araligin 1. elemani
									 //y:araligin 2. elemani
									 //limit hata payi

	if(func(x)*func(y)>0){// Araligin Uc Degerlerinin Fonksiyon Sonuclarinin Isaretlerinin Ayni Olma Durumu
		printf("\nNo Comment\n");
		return 0;
	}else if(func(x)*func(y)==0){// Araligin Uc Degerlerinin Fonksiyon Sonuclarindan En Az Bir Tanesinin Kok Olma Durumu
		printf("\nRoot Of This Problem is %Lf\n", func(x) ? y:x);
	}else{// Araligin Uc Degerlerinin Fonksiyon Sonuclarinin Isaretlerinin Farkli Olma Durumu
		if(0){//RegulaFalsi Ile Cozum #####################################################################################################################
			printf("\n");
			long double z=x,before;
			char a=0;
			do{
				before=z;//Bi Onceki Sonucu Ramde Tutuyoruz Ki Hata Oranini Yazalim
				z=RegulaFalsi(x,y);//Iterasyon Adimi
				if(func(x)*func(z)<0)//Iterasyon Adimi Sonucu Cikan Kokun Saginda Mi ,Solunda Mi ? Kontrolu
					y=z;
				else
					x=z;
				printf("%d. Step [%.8Lf<->%.8Lf] Now Result:%.8Lf\n",++a,x,y,func(z));
			}while(fabs(before-z)>=limit);//Verdigimiz Limit Altinda Hata Yapmak Icin Gerekli Dongu
			printf("\nResult Of %.8Lf is %Lf with %e Error\n",z,func(z),fabs(0.0-func(z)));
		}else if(1){//BiSection Yontemi Ile Cozum #############################################################################################################
			printf("\n");
			long double z=y,before;
			char a=0;
			do{
				before=z;//Bi Onceki Sonucu Ramde Tutuyoruz Ki Hata Oranini Yazalim
				z=BiSection(x,y);//Iterasyon Adimi
				if(func(x)*func(z)<0)//Iterasyon Adimi Sonucu Cikan Kokun Saginda Mi ,Solunda Mi ? Kontrolu
					y=z;
				else
					x=z;
				printf("%d. Step [%.8Lf<->%.8Lf] Now Result:%.8Lf\n",++a,x,y,func(z));
			}while(fabs(before-z)>limit);//Verdigimiz Limit Altinda Hata Yapmak Icin Gerekli Dongu
			printf("\nResult Of %.32Lf is %.32Lf with %e Error\n",z,func(z),fabs(0.0-func(z)));
		}else if(0){//NewtonRhapson Yontemi Ile Cozum #########################################################################################################
			if(0){//((func(x)*DifforNR(x)))/pow(Diff(x),2)>=1||(Diff(Diff(x))*func(x)<=0)){//Ayrica Yapilmasi Gereken Konroller
				printf("\nNo Comment\n");
				return 0;
			}else{
				printf("\n");
				long double before,z=x;// Ust Limitten Mi Baslamali Alt Limitten, Mi Baslamali? &&&&&&&&&&&&&&&&&&&&&&&&&&
				char a=0;
				do{
					before=z;//Bi Onceki Sonucu Ramde Tutuyoruz Ki Hata Oranini Yazalim
					z=NewtonRhapson(z);//Iterasyon Adimi
					printf("%d. Step [%.8Lf] Now Result:%.8Lf\n",++a,z,func(z));
				}while(fabs(before-z)>limit);//Verdigimiz Limit Altinda Hata Yapmak Icin Gerekli Dongu
				printf("\nResult Of %.8Lf is %Lf with %e Error\n",z,func(z),fabs(0.0-func(z)));
			}
		}else{// BasicIteration Yontemi Ile Cozum ###############################################################################################################
			if(DifforIT(x)<=0||DifforIT(y)<=0){//Ayrica Yapilmasi Gereken Konroller
				printf("\n*No Comment\n");
				return 0;
			}else{
				printf("\n");
				long double before,z=x;// Ust Limitten Mi Baslamali Alt Limitten, Mi Baslamali? &&&&&&&&&&&&&&&&&&&&&&&&&&
				char a=0;
				do{
					before=z;//Bi Onceki Sonucu Ramde Tutuyoruz Ki Hata Oranini Yazalim
					z=BasicIteration(z);//Iterasyon Adimi
					printf("%d. Step [%.8Lf] Now Result:%.8Lf\n",++a,z,func(z));
				}while(fabs(before-z)>limit);//Verdigimiz Limit Altinda Hata Yapmak Icin Gerekli Dongu
				printf("\nResult Of %.8Lf is %Lf with %e Error\n",z,func(z),fabs(0.0-func(z)));
			}
		}
	}
}