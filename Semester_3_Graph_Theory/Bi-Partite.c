#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool minictrl(int v,bool *colorpacket,bool *mi,bool *travel,int z){
	int i;
	for(i=0;i<v;i++){
		if(mi[i]){
			if(!travel[i]){
				travel[i]=1;
				colorpacket[i]=!colorpacket[z];
			}else if(colorpacket[i]==colorpacket[z]){
					return false;
			}
		}
	}
	return true;
}
bool minminictrl(int v,bool *travel,bool *mi,bool *colorpacket){
	int i;
	for(i=0;i<v;i++)
			if(mi[i]&&travel[i])
				return !colorpacket[i];
	return 1;
}
bool ctrl(int v,bool **bm){
	bool *colorpacket=(bool *)malloc(sizeof(bool)*v);
	bool *travel=(bool *)malloc(sizeof(bool)*v);
	int i,j;
	for(i=0;i<v;i++)
		travel[i]=0;
	for(i=0;i<v;i++){
		if(!travel[i]){
			travel[i]=1;
			colorpacket[i]=minminictrl(v,travel,bm[i],colorpacket);
			if(!minictrl(v,colorpacket,bm[i],travel,i))
				return false;
		}else{
			if(!minictrl(v,colorpacket,bm[i],travel,i))
				return false;
		}
	}
	
	for(i=0;i<v;i++)
		printf("\n%d)-------%s",i,colorpacket[i] ? "Red":"Blue");
	return true;
}
bool control(bool **a,int v){
	int i,j;
	for(i=0;i<v;i++){
		if(!a[i][i])
			return false;
		for(j=0;j<v;j++)
			if((a[i][j]!=true&&a[i][j]!=false)||a[i][j]!=a[j][i])
				return false;
	}
	return true;
}
int main(){
	n1:
	printf("\nLutfen Matrisiniz Ilk Satirinizi (-1) e Basincaya Kadar Giriniz\n");
	int cc=10;
	bool *b=(bool *)malloc(cc*sizeof(bool));
	int i=0;
	do{
		int f;
		printf("\n a[0][%d]: ",i);
		scanf("%d",&f);
		if(f!=-1){
			i++;
			if(cc-1<=i){
				cc+=10;
				b=(bool *)realloc(b,cc*sizeof(bool));
			}
			b[i-1]=f;
			continue;
		}else
			break;
	}while(1);
		
	int c,v=i;
	bool **a=(bool **)malloc(v*sizeof(bool *));
	a[0]=(bool *)malloc(v*sizeof(bool));
	
	for(i=0;i<v;i++)
		a[0][i]=b[i];
	free(b);
	
	for(i=1;i<v;i++){
		a[i]=(bool *)malloc(v*sizeof(bool));
		int j;
		for(j=0;j<v;j++){
			printf("\n a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	int j;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			printf("\t %d",a[i][j]);
		printf("\n");
	}

	//if(control(a,v)){
	//	printf("\n Matris Yanlis! ,Tekrar Deneyiniz!\n");	
	//	goto n1;
	//}
	printf("\nBu Graf %s'dir",ctrl(v,a) ?"Bipolar":"Bipolar Degil");

}
