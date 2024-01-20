#include<stdio.h>
int main() {
	char a[20];
	printf("\nLutfen Bir Karakter Dizisi Giriniz.\n");
	scanf("%[^\n]s",a);
	int i;
	for(i=0;a[i];i++)
		printf("%c",a[i]);

}