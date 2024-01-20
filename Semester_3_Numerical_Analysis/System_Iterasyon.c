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
double fy(double x,double y){
	return 0.1*x*pow(y,2)+0.1*x+0.8;//////////////////////////////////////////
}
double fx(double x,double y){
	return 0.1*pow(x,2)+0.1*pow(y,2)+0.8;////////////////////////////////////
}
double f1(double x,double y){
	return 0.1*x*pow(y,2)+0.1*x-y+0.8;///////////////////////////////////////
}
double f2(double x,double y){
	return 0.1*pow(x,2)+0.1*pow(y,2)-x+0.8;//////////////////////////////////
}
int main(){
	double x1=0.5,y1=0.5,limit=pow(10,-6);///////////////////////////////////
	int i=0;
	double x2=x1,y2=y1;
	do{
		printf("\nX%d=%lf,Y%d=%lf\n",i,x2,i,y2);
		++i;
		x2=fx(x1,y1);
		y2=fy(x1,y1);
		if(fabs(x1-x2)<limit&&fabs(y1-y2)<limit)
			break;
		x1=x2;
		y1=y2;
	}while(1);
	printf("\nFirst F=%lf\nSecond F=%lf\nx=%lf,y=%lf\n",f1(x2,y2),f2(x2,y2),x2,y2);
}