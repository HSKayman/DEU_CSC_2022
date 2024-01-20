#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#define X 10
#define ITER 10                
#define NONE 0                  
int main(int argc, char **argv){
	int start,end,j,k,i,id,size;
   float heatmap[2][X+2][X+2]={0};
   MPI_Status status; 

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
   MPI_Comm_size(MPI_COMM_WORLD, &size);
   int process=X/size;
   if(id==0){
      for(i=1;i<X-1;++i)
         for(j=1;j<X-1;++j)
            heatmap[0][i][j]=(i*(X-i-1)*j*(X-j-1));


         printf("%d  !",size);
    	for(i=1;i<size;++i){
         start=id*process+1;
         end=(id+1)*process+1;
         if(end>X)
            end=X;
         MPI_Send(&heatmap[0][start][0],(end-start)*process, MPI_FLOAT,i,0,MPI_COMM_WORLD);
         }
      
   }
   start=id*process+1;
   end=(id+1)*process+1;
   if(end>X)
      end=X;
    int up= id== 0      ? -1:id-1;
    int down  = id== size-1 ? -1:id+1;
    if(id!=0){
       MPI_Recv(&heatmap[0][start][0],(end-start)*process, MPI_FLOAT,0,0,MPI_COMM_WORLD,&status);

   }
    for(i=0;i<ITER;++i){
      printf("22222%d\n",id);
      if(down!=-1){
         MPI_Send(&heatmap[0][start-1][0],X,MPI_FLOAT,down,2,MPI_COMM_WORLD);
         MPI_Recv(&heatmap[0][end][0],X,MPI_FLOAT,down,1,MPI_COMM_WORLD,&status);
      }
      if(up!=-1){
         MPI_Recv(&heatmap[0][start-1][0],X,MPI_FLOAT,up,2,MPI_COMM_WORLD,&status);
         MPI_Send(&heatmap[0][end][0],X,MPI_FLOAT,up,1,MPI_COMM_WORLD);
      }
    	for(j=start;j<end;++j)
         for(k=1;k<X-1;++k)
            heatmap[1][j][k]=heatmap[0][j][k]+0.1*(heatmap[0][j-1][k]+heatmap[0][j+1][k]-2.0*heatmap[0][j][k])+0.1*(heatmap[0][j][k-1]+heatmap[0][j][k+1]-2.0*heatmap[0][j][k]);
   
      for(j=start-1;j<end+1;++j)
         for(k=1;k<X-1;++k)
            heatmap[0][j][k]=heatmap[1][j][k];
      
      }
    	if(id==0){
         for(i=1;i<size;++i){
            MPI_Recv(&start,1,MPI_INT,i, 3, MPI_COMM_WORLD,&status);
            MPI_Recv(&end,1,MPI_INT,i, 4, MPI_COMM_WORLD,&status);
            MPI_Recv(&heatmap[0][start][0],(end-start)*process,MPI_FLOAT,i, 5, MPI_COMM_WORLD,&status);
         }
         FILE *fp;
         fp = fopen("w.txt", "w");
         for(i=0;i<X+2;++i){
            for(j=0;j<X+2;++j){
               fprintf(fp,"%.2f",heatmap[0][i][j]); 
            }
            fprintf(fp,"\n"); 
         }
    	}else{
         MPI_Send(&start,1,MPI_INT,0, 3, MPI_COMM_WORLD);
         MPI_Send(&end,1,MPI_INT,0, 4, MPI_COMM_WORLD);
         MPI_Send(&heatmap[0][start][0],(end-start)*process,MPI_FLOAT,0, 5, MPI_COMM_WORLD);
      }
      MPI_Finalize();
}