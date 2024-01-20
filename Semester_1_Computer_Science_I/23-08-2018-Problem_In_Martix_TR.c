#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include<conio.h>
int main()
{
int i,j,n;
int mat[10][10],hata[16];
printf("Satir Sutun Sayisi : ");
scanf("%d",&n);

for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
printf("%d.satir, %d.sutun elemani : ",i,j);
scanf("%d",&mat[i][j]);
}
for(i=0;i<n;i++)
hata[i]=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(mat[i][j]==0) hata[i]++;
for(i=0;i<n;i++)
printf("%d.sutundaki hata sayisi : %d\n",i,hata[i]);
getch();
}