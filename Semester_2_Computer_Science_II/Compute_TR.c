#include<stdlib.h>
#include<time.h>
int fac(int x){
   if(x==1)
    return 1;
   else
    return(x)*(fac(x-1));
}
void hesap(int **);
int main(){
  int i;
  int **a;
  a=(int **)malloc(50*sizeof(int *));
  srand(time(0));
  for(i=0;i<50;i++){
    a[i]=(int *)malloc(4*sizeof(int));
    a[i][0]=rand()%6+1;//a
    a[i][1]=rand()%4+1;//b
    a[i][2]=rand()%5+1;//c
    printf("%d \t%d \t%d\n",a[i][0],a[i][1],a[i][2]);
  }
  hesap(a);
  printf("\n\n\n\n\n\n\n\n\n\n(a,b,c)=(%d,%d,%d)=max y=%d",a[0][0],a[0][1],a[0][2],a[0][3]);
  getchar();
  getchar();
  getchar();
}

void enbhesap(int **a){
  int i,max=a[i][3];
  for(i=0;i<50;i++){
      if(max<=a[i][3]){
        max=a[i][3];
        a[0][0]=a[i][0];
        a[0][1]=a[i][1];
        a[0][2]=a[i][2];
        a[0][3]=max;

      }
  }
}
void hesap(int **a){
    int i;
    for(i=0;i<50;i++){
        a[i][3]=fac(a[i][0])/(a[i][1]*a[i][2]);
        }
    enbhesap(a);
}