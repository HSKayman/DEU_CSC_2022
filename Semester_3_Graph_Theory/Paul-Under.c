#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void diva(char *a,char x,char *z){
	int i,c=-1;
	for(i=0;i<strlen(a);++i){
		if(a[i]==x)
			continue;
		else
			z[++c]=a[i];
	}
}
int lg=0;
char result[6];
void PaulUnder(char *c,bool **p,int v){
	printf("\n%s",c);
	int i,j;
	bool flag=true;
	for(i=0;i<strlen(c);++i){
		for(j=i+1;j<strlen(c);++j){
			if(p[c[i]-48][c[j]-48]==true){
				flag=false;
				char *k=(char *)malloc(strlen(c)-1);
				diva(c,c[i],k);
				PaulUnder(k,p,v-1);
				diva(c,c[j],k);
				PaulUnder(k,p,v-1);
				return;
			}
		}
	}
	if(flag&&strlen(c)>lg){			
		i=strlen(c)-1;
		printf("\n**%s",c);
		strcpy(result,c);
		lg=strlen(c);
	}
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
			if(f==1)
				b[i-1]=true;
			else if(f==0)
				b[i-1]=false;
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
			int f;
			scanf("%d",&f);
			if(f==1)
				a[i][j]=true;
			else if(f==0)
				a[i][j]=false;
		}
	}
	int j;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			printf("\t %s",a[i][j] ? "true" : "false");
		printf("\n");
	}
	char *size=(char *)malloc(sizeof(char)*v);
	for(i=0;i<v;++i)
		size[i]=i+48;
	PaulUnder(size,a,v);
	printf("\n\n%s",result);
}