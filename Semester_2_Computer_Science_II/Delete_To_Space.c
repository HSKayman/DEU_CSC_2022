#include<stdio.h>
int main(){
	char a[1000];
	scanf("%[^\n]s",a);
	int i;
	printf("\n\n\n\n\n");
	for(i=0;a[i];i++){
		if(a[i]==32)
			printf("\n");
		else
			printf("%c",a[i]);
	}


}