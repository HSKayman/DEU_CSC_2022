#include<stdio.h>
#include<stdlib.h>
void Transirdel(float**p,int a,int b);
void TransPrivoit(float**p,int b,int c);
void InCtrl(float **p,int a,int b);
int main(){
	float **a;
	printf("Lutfen Matrislerin Boyutlarini giriniz");
	int c,b;
	scanf("%d %d",&c,&b);
	a=(float**)malloc(c*sizeof(float*));
	int i,j;
	for(i=0;i<c;i++){
		a[i]=(float*)malloc(b*sizeof(float));
		for(j=0;j<b;j++){
			printf("\na[%d][%d]:",i,j);
			scanf("%f",&a[i][j]);
		}
	}
	printf("\n\n\n\n*****************\n\n");
	for(i=0;i<c;i++){
		for(j=0;j<b;j++)
			printf("%.2f  ",a[i][j]);
		printf("\n");
	}
	TransPrivoit(a,c,b);
	printf("\n\n\n\n*******************\n\n\n");
	InCtrl(a,c,b);
	for(i=0;i<c;i++){
		for(j=0;j<b;j++)
			printf("%.2f  ",a[i][j]);
		printf("\n");
	}
	Transirdel(a,c,b);
	printf("\n\n\n\n\n*******************\n\n\n\n");
	for(i=0;i<c;i++){
               for(j=0;j<b;j++)
                       printf("%.2f  ",a[i][j]);
               printf("\n");
        }

getchar();
getchar();
getchar();
getchar();
getchar();
getchar();
}
int ZeroCtrl(float**p,int a,int b){
	int i,j;
	for(j=0;j<b;j++)
		if(p[a][j]!=0)
			return 0;
	return 1;
}
void Swap(float**p,int b,int c,int a){
	int j;
	for(j=0;j<b;j++){
		float swap=p[c][j];
		p[c][j]=p[a][j];
		p[a][j]=swap;
	}
}
void InCtrl(float**p,int a,int b){
	int i,j;
	for(i=0;i<a;i++)
		if(ZeroCtrl(p,i,b))
			for(j=i+1;j<a;j++)
				Swap(p,b,j,j-1);
}
void TransPrivoit(float**p,int a,int b){
	int step,step2=0;
	for(step=0;step<a;step++){
		int i,j,f=0;
		for(i=step;i<a;i++){
			if(p[i][step2]!=0){
				Swap(p,b,i,step);
				f=1;
				break;
			}else if(i+1==a&&step2+1<b){
				i=step-1;
				step2++;
			}
		}
		if(f){
			float dv=p[step][step2];
			for(i=b-1;i>=0;i--)
				p[step][i]/=dv;


			for(i=step+1;i<a;i++)
				if(p[i][step2]!=0){
					float dvr=p[i][step2];
					for(j=0;j<b;j++)
						p[i][j]-=dvr*p[step][j];
				}
		}
	if(step2+1<b)
		step2++;
	}
}
void Transirdel(float**p,int a,int b){
	int i,j,k,l;
	for(i=a-1;i>=0;i--)
		for(j=b-1;j>=0;j--)
			if(p[i][j]==1)
				for(k=i-1;k>=0;k--)
					if(p[k][j]!=0){
						float dvr=p[k][j];
						for(l=0;l<b;l++)
							p[k][l]-=dvr*p[i][l];
					}
}
