#include <stdio.h>
int main(){
	FILE *islem;
	islem= fopen("carpimtablosu.txt","w");
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			fprintf(islem,"%d\t",i*j);
		}
		fprintf(islem,"\n");
	}
	fprintf(islem,"\nallah allah");
	
	fclose(islem);
		FILE *islem2;
	islem2= fopen("deneme.txt","r");
	while(!feof(islem2)){
		fgetc(islem2);
	fclose(islem);
	
}