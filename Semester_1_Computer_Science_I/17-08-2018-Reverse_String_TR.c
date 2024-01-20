#include<stdio.h>
#include<stdio.h>
int main(){
	char name[30]; scanf("%s",&name); 
	int l=strlen(name);
	//printf("%d\n %s",tall,ad);
	printf("\n\n\n\n\n");
	for(int i=l-1;i>=0;i--){
		printf("\n%d \t%c",i+1,name[i]);
	}
}