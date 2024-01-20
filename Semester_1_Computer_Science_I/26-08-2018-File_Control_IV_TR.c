#include<stdio.h>
int main(){
	FILE *file1;
	file1=fopen("islem1.txt","w");
	fprintf(file1,"26");
	fclose(file1);
	FILE *file2;
	file2=fopen("islem2.txt","w");
	fprintf(file2,"43");
	fclose(file2);
	file1=fopen("islem1.txt","r");
	file2=fopen("islem2.txt","r");
	int a,b;
	fscanf(file1,"%d",&a);
	fclose(file1);
	fscanf(file2,"%d",&b);
	fclose(file2);
	FILE *file3;
	file3=fopen("sonuc.txt","w");
	fprintf(file3,"%d",a+b);
	fclose(file3);
	printf("Gorev Basarili :)");
	FILE *file;
	char buffer[11];
	file=fopen("asas.txt","r");
	fread(buffer,1,10,file);
	buffer[10]=0;
	fclose(file);
	printf("dosyanin ilk 10 karakteri :\n%s\n", buffer);
	char c[]="Suca";
	FILE *file5;
	file5=fopen("asas.txt","w");
	fwrite(c,1,4,file5);
	fclose();
	
}