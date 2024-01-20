#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"mpi.h"

char message[20];
int type=99;
MPI_Status status;

void producer(int i)
{
	switch (i % 5) {
	case 0: strcpy(message, "Selam,"); break;
	case 1: strcpy(message, "bu mesaj"); break;
	case 2: strcpy(message, "tekrar"); break;
	case 3: strcpy(message, "ve tekrar"); break;
	case 4: strcpy(message, "yollanacaktır."); break;
	}
	MPI_Send(message,strlen(message)+1,MPI_CHAR,1,type,MPI_COMM_WORLD);
}
void consumer()
{
	MPI_Recv(message,20,MPI_CHAR,0,type,MPI_COMM_WORLD,&status);
	printf( "%s\n", message);
}
void main(int argc, char **argv ) {
	int i,rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if (rank == 0) {
		for (i=0; i<30; i++)
			producer(i);
	} else {
		for (i=0; i<30; i++) // Recv adedi <= Send adedi olmalı.
			consumer(); // Aksi takdirde çalışmaz.
	}
	MPI_Finalize();
}