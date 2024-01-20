#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct telrehber{
	char name[20];
	int no;
	char city[20];
	
}tel[3];


int main(){
	
	for(int i=0;i<3;i++){
		printf("%d. kisinin adi:",i+1); scanf("%s",&tel[i].name);
		printf("%s kisinin yasadigi sehiri:",tel[i].name); scanf("%s",&tel[i].city);
		printf("%s kisinin numarasi:",tel[i].name); scanf("%d",&tel[i].no);
	}
	
	printf("\n\n\nREHBER\n\n\n");
	
	for(int i=0;i<3;i++){
	printf("%s\t\t%s\t\t%d\n",tel[i].name,tel[i].city,tel[i].no);
	}

}