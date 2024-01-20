#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"omp.h"
int main(int argc, char *argv[])
{
	//Parse
	char targetFileName[15],rootFileName[15];
	if(argc==3){
      strcpy(rootFileName,argv[1]);
      strcpy(targetFileName,argv[2]);
  	}else if(argc==2){
  		strcpy(rootFileName,argv[1]);
  		strcpy(targetFileName,"output.txt");
  	}else if(argc==1){
  		strcpy(rootFileName,"input.txt");
  		strcpy(targetFileName,"output.txt");
  	}else{
  		printf("Usage: outFile <rootFileName> <targetFileName> \noutFile <targetFileName> \noutFile \n");
      	return 0;
  	}
  	//Read to file
	FILE *filePointer;
	if ((filePointer = fopen (rootFileName, "r")) == NULL) {
      printf("Open Root File Error!\n");
      return 0;
  	}
  	
  	unsigned Related[4]={0};
  	/*Related[0] vipTicket
	  Related[1] normalTicket 
	  Related[2] buyerVipTicket 
	  Related[3] buyerNormalTicket*/
  	fscanf(filePointer, "%d\n%d\n\n%d\n%d",&Related[0],&Related[1],&Related[2],&Related[3]);
  	fclose(filePointer);
	


	/*We need to stay away from the parallel programming blog so 
	that we can write the numbers beautifully to the file, so 
	we should keep the thread numbers in one place.*/
	unsigned **Tickets=(unsigned **)malloc(2*sizeof(unsigned *));
	Tickets[0]=(unsigned *)calloc(Related[0],sizeof(unsigned));
	Tickets[1]=(unsigned *)calloc(Related[1],sizeof(unsigned));
	if(Tickets[0]==NULL||Tickets[1]==NULL){
      printf("Memory Allocate Error!\n");
      return 0;
  	}
  	int i,backUps=Related[1];
  	//Here we go
	omp_set_num_threads(Related[2]+Related[3]);
	#pragma omp parallel shared(Tickets,Related,backUps),private(i)
	{
		if(omp_get_thread_num()<Related[2]){
			for(i=0;i<Related[0];++i){
				#pragma omp critical
				{
					if(Tickets[0][i]==0){//There may be ticket thieves if the "if blog" were out of critical blog
						Tickets[0][i]=omp_get_thread_num()+1;
						i=Related[0];//break; alternative because it is not working here.
					}
				}
			}
		}
		else{
				#pragma omp critical
				{
					if(backUps>0)//There may be ticket thieves if the "if blog" were out of critical blog
						Tickets[1][--backUps]=omp_get_thread_num()+1;
				}
		}
	}

	//Write to file and Print to Screen
	if((filePointer=fopen(targetFileName,"w"))==NULL){
      printf("Open Target File Error!\n");
      return 0;
  	}
  	
  	//First VIP
	for(i=0;i<Related[0];++i){
		fprintf(filePointer,"%d - %d\n",i+1,Tickets[0][i]);
		printf("%d - %d\n",i+1,Tickets[0][i]);
	}
	
	printf("\n-----------------------\n");
	fprintf(filePointer, "\n");

	//Second Normal
	for(i=0;i<Related[1];++i){
		fprintf(filePointer, "%d\n",Tickets[1][i]);
		printf("%d\n",Tickets[1][i]);
	}
	return 1;
}