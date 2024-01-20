#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <mpi.h>
#define MAXSIZE 1000

int main(int argc, char **argv) {
	int myid, numprocs, i, x;
	int low, high;
	char fn[255];

	FILE *fp;
	int data[MAXSIZE];
	int myresult=0, result=0;
	double start=MPI_Wtime();

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	
	/* rand_data.txt dosyasindan veriler okunur */
	if (myid == 0) {
		
		for (i = 0; i < MAXSIZE; i++)
			data[i]=rand()%2000;
	}
	/* Veriyi (tum dosyayi) yayinla */
	MPI_Bcast(data, MAXSIZE, MPI_INT, 0, MPI_COMM_WORLD);
	
	x = MAXSIZE/numprocs; /* Benim ilgilenecegim kisim */
	low = myid * x;
	high = low + x;
	
	for(i = low; i < high; i++)
		myresult += data[i];
	
	/* Genel toplami bul */
	printf("Ben surec-%d, %d degerini hesapladim.\n",
	myid, myresult);
	MPI_Reduce(&myresult, &result, 1, MPI_INT, MPI_SUM,0, MPI_COMM_WORLD);
	if (myid == 0)
		printf("The sum is %d found in %.2f seconds.\n",result, MPI_Wtime()-start);
	
	MPI_Finalize();
	
	return 0;
}