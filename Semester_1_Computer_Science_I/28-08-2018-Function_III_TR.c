/*
 * Function III practice program.
 * CSC I intro programming exercise.
 */
#include<stdio.h>
int f(int x){
printf("%d",x);
	if(x>1)
		f(x-1);
		
}int main(void){
	f(3);
}
