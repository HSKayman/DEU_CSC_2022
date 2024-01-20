#include<stdio.h>
#include<math.h>
double f1(double x,double y){
	return 4*x*x + y*y*y + 28;
}
double f2(double x,double y){
	return 3*x*x*x + 4*y*y - 145;
}
double lineea(double x,double y,int q){
	double h=pow(10,-10);
	if(q==0)
		return (f1(x+h,y)-f1(x,y))/h;
	else if(q==1)
		return (f1(x,y+h)-f1(x,y))/h;
	else if(q==2)
		return (f2(x+h,y)-f2(x,y))/h;
	else	
		return (f2(x,y+h)-f2(x,y))/h;
	
} 
double Newthon_Rhapson(double x,double y,int q){
	if(q==0){
		return(x-((f1(x,y)*lineea(x,y,3)-f2(x,y)*lineea(x,y,1))/
				(lineea(x,y,0)*lineea(x,y,3)-lineea(x,y,1)*lineea(x,y,2))));
	}else{
		return(y-((f2(x,y)*lineea(x,y,0)-f1(x,y)*lineea(x,y,2))/
				(lineea(x,y,0)*lineea(x,y,3)-lineea(x,y,1)*lineea(x,y,2))));
	}
}
int main(){
	double x1=1,y1=1,limit=pow(10,-8);
	double x2=x1,y2=y1;
	int i=0;
	//printf("%lf",f1(x1,x2));
	do{
		printf("\nX%d=%lf,Y%d=%lf\n",i,x2,i,y2);
		++i;
		x2=Newthon_Rhapson(x1,y1,0);
		y2=Newthon_Rhapson(x1,y1,1);
		if(fabs(x1-x2)<limit&&fabs(y1-y2)<limit)
			break;
		x1=x2;
		y1=y2;
	}while(1);
	printf("\nFirst F=%lf\nSecond F=%lf\nx=%lf,y=%lf\n",f1(x2,y2),f2(x2,y2),x2,y2);

}