#include<stdio.h>
#define N 3
int ctrl(int a[N][N]);
int simctrl(int a[N][N]);
int tsimctrl(int a[N][N]);
int tctrl(int a[N][N]);
int main(){
	int i,j,a[N][N];
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
		printf("\n a[%d][%d] :",i+1,j+1);
		scanf("%d",&a[i][j]);
		}
	if(ctrl(a))
		printf("Bu Matris ust ucgendir");
	if(simctrl(a))
		printf("\n Bu Matris simetriktir");
	if(tsimctrl(a))
		printf("\n BU Matris Ters Simetriktir");
	if(tctrl(a))
		printf("\n BU Matris alt ucgendir");


}
int ctrl(int a[N][N]){
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<i;i++)
			if(a[i][j]!=0)
				return 0;
return 1;
}
int simctrl(int a[N][N]){
	int i,j;
	for(i=0;i<N;i++)
		for(j=i;j<N;j++)
			if(a[i][j]!=a[j][i])
				return 0;
	return 1;
}
int tsimctrl(int a[N][N]){
	int i,j;
	for(i=0;i<N;i++)
		for(j=i;j<N;j++)
			if(a[i][j]!=-1*a[j][i])
				return 0;
	return 1;
}
int tctrl(int a[N][N]){
	int i,j;
	for(i=0;i<N;i++)
		for(j=i;j<N;j++)
			if(a[i][j]!=0)
				return 0;
	return 1;
}
