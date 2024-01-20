#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void saysisayisal(){
	srand(time(NULL));
	for(int i=0;i<10;i++){	
		int d=9+rand()%92;
		printf("%d\t",d);
	}

}
void zarat(){
	srand(time(NULL));  
	int deger=1+rand()%100;
	printf("%d",deger);
}
void render(int len, int tal){
	for(int i=0; i<tal; i++){
		for(int j=0; j<len; j++){
			printf("*");
		}
	printf("\n");
	}
}
int main(){
	zarat();
	printf("Lutfen cizilecegin boyunu giriniz: "); int a; scanf("%d",&a);
	printf("Lutfen cizilecegin eni giriniz: "); int b; scanf("%d",&b);
	render(b,a);
	saysisayisal();
}
