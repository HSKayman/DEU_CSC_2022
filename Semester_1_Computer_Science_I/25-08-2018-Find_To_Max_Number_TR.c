#include <stdio.h>
int max(int *a,int lenght){
	int maks=a[0];
	for(int i=1;i<lenght;i++){
	if(*(a+i)>maks)
	maks=a[i];

}
return maks;}



int main(){
	int number[5]={1,3,4,42,100};
	int a=5;
	int max1=max(number,5);
	printf("Bu dizideki en buyuk eleman %d'dir",max1);	
	
	
}