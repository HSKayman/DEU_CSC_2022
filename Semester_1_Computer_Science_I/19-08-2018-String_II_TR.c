#include <stdio.h>
#include <string.h>
int main(){
	
	printf("kac kelime gireceksiniz :"); int f; scanf("%d",&f);
	char a[f+1][20];
	for(int i=0;i<f;i++){
		printf("%d. Kelime :",i+1); scanf("%20s",&a[i]);	
	}
	system("CLS");
	for(int i=0;i<f;i++){
		for(int j=0;j<f-i;j++){
			if(strcmp(a[j+1],a[j])<0){
			char g[20];
			strcpy(g,a[j]);
			strcpy(a[j],a[j+1]);
			strcpy(a[j+1],g);
			} 
		}}
	printf("\n+++++++++++++++++++++++++++++++++++++++\n");
	int i=0;
	while(i<f+1){
		printf("%s\n",a[i]);
	i++;
	}}
	int main(){
		char a[20];
		printf("Adiniz :"); scanf("%20s",&a);
		for(int i=strlen(a)-1; i>=0;i--){
			printf("%c",a[i]);
		}
	//++++++++++++++++++++++++++++++++++++++++++++
	char b[20];
	printf("\n\nAdiniz :"); scanf("%20s",&b);
	printf("%s",strrev(b));
	
	}