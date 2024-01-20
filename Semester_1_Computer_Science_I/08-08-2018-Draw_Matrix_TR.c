#include<stdio.h>
int main(){
int a,s,i,j;
printf("Lutfen Ust taban boyutunu giriniz:"); scanf("%d",&a);
for(i=1;i<a;i++){
	for(s=1;s<=i;s++){
		printf(" ");
	}
	for(j=1;j<=a-i;j++){
		printf("*");
		
	}
	printf("\n");
} 
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			if(i==j)
			printf("1");
			else
			printf("0");
		}
		printf("\n");
	}
for(i=0;i<=10;i++){
		
		for(j=0;j<=10;j++){
			if((i%2==1 && j%2==0) || (i%2==0 && j%2==1))
				printf("\\");

			else
			printf("*");
		}
	printf("\n");
	}
for(int i=0;i<=10;i++){
		
		for(int j=0;j<=10;j++){
			if(i==0 || i==10 || j==0 || j==10)
			printf("*");
			else
			printf(" ");
		}
	printf("\n");
	
}
for(int i=0;i<=10;i++){
		for(int j=0;j<=i;j++){
			printf("%d\t",j);
		}
	printf("\n");
	
}
int s=1;
printf("karenizin kose uzunlugu birimi : "); scanf("%d",&a);
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			printf("%d \t",s);
			s++;
		}
		printf("\n");
	}
}