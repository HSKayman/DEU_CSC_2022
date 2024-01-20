#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char isim[10]="melek",isim2[10];
	strcpy(isim2,isim);
	printf("%s",isim2);
	printf("\n\n Merhaba %s",strcpy(isim,"Ali"));
	char mes[]="Merhaba ",mes2[]="Dunya ";
	//strcat(mes,mes2);
	printf("%s",strcat(mes2,mes));
	system("CLS");
	char mes3[]="Merhaba ",name[10],namecopy[10];
	printf("Name :"); scanf("%s",&name);
	strcpy(namecopy,name);
	printf("%s\n%d",strcat(mes3,namecopy),strlen(name));
	char string[4]; //The max number of letters for "yes".

     printf("Would you like to play?");
     scanf("%3s", string);
	printf("%s",string);
	char str[]; scanf("%s",&str);
	printf("%s",str);
}