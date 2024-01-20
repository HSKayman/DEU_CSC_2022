#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//The function
double func(double x,double* coefficients,int coefficient){
	double result=0;
	int i=0;
	while(coefficient>0){
		result+=coefficients[i]*pow(x,coefficient);
		--coefficient;
		++i;
	}
	return result;
}

int main(){
	

	//Read to File
	FILE *filePointer;
	if ((filePointer = fopen ("input.txt", "r")) == NULL) {
      printf("Open Root File Error!\n");
      return 0;
  	}
  	

  	//Read to Requires Data
  	int i,coefficient=0,minormax=-1;//minimum(-1) or max(1) <=======
  	fscanf(filePointer, "%d\n",&coefficient);
  	double *coefficients=(double *)calloc(coefficient,sizeof(double));
  	if(coefficients==NULL){
  		printf("Memory Allocation Error!\n");
      	return 0;
  	}
  	for(i=0;i<coefficient;++i){
  		fscanf(filePointer, "%lf",&coefficients[i]);
  		coefficients[i]*=minormax;
  	}
  	double epsilon=0,a=0,b=0;
  	fscanf(filePointer, "\n%lf",&epsilon);
  	fscanf(filePointer,"\n%lf %lf",&a,&b);
  	fclose(filePointer);


	//Write to File
	if((filePointer=fopen("output.txt","w"))==NULL){
      printf("Open Target File Error!\n");
      return 0;
  	}
	fprintf(filePointer,"%lf %lf\n",a,b); 
	double r=(sqrt(5)-1)/2,x1,x2;//Golden Ratio r=0.618


  	//Iteration is Ready!
	do{
		x1=b-r*(b-a);
		x2=a+r*(b-a);
		if(func(x1,coefficients,coefficient)<func(x2,coefficients,coefficient))
			a=x1; //   (x1,b]
		else
			b=x2; //   [a,x2)
		fprintf(filePointer,"%lf %lf\n",a,b); 
	}while((b-a)>epsilon);
	fclose(filePointer);
}
