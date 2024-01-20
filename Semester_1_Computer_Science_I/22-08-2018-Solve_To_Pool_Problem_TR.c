#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  int main(){
  	printf("Makinamiza Hosgeldiniz.\n+++++++++++++++++++++++++++++++++++\n");
  	printf("Bu makina Havuz problemlerinin hepsini cozmektedir.\n");
  	int d[99],i=0,f;
  	while(f!=-1){
  		printf("\n%d. havuzu dolduran cesmenin kac saatde doldurduguna yaziniz :\n Islemizin bittiyse -1 i girin",i+1);
  		scanf("%d",&f);
  		if(f!=-1){
  		d[i]=f;
		i++;}
	  }
	  int d2[99],j=0,f2;
	   	while(f2!=-1){
  		printf("%d. havuzu bosaltan cesmenin kac saatde bosalttigini yaziniz :\n Islemizin bittiyse -1 i girin",j+1);
  		scanf("%d",&f2);
  		if(f2!=-1){
  		d2[j]=f2;
		j++;}
	  }
	  float a=0.00;
	  for(int k=0;k<i;k++){
	  	a=1/(float)d[k]+a;
	  }
	  float b=0;
	  for(int l=0;l<j;l++){
	  	b=(-1/(float)d2[l])+b;
	  }
	  float s=a+b;
	  printf("\n%d kadar cesmeyle dolduruyorsunuz\n%d kadar cesmeyle bosaltiyorsunuz\n Bu havuz %.2f saatde havuzu doldurur.",i,j,1/s);
	  
	  void degistir(int *a){
	  	*a=5;
	  }
	  int main(){
	  	int a = 2 ;
		degistir(&a);
		printf("%d",a);
	  }