#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char Stdno[10];
	int  StdMark;
}Dic;
void f(Dic *a);
int main(){
	Dic a;
	a.StdMark=100;
	printf("%d\n",a.StdMark);
	strcpy(a.Stdno,"Suca");
	f(&a);
	printf("%d",a.StdMark);
	int i;
	Dic c,a={"Ali",100},b,*ad;
	b=a;
	printf("\n%s %d\n",b.Stdno,b.StdMark);
	ad=&a;
	printf("%s %d\n",ad->Stdno,ad->StdMark);
	memcpy(c.Stdno,a.Stdno,sizeof(a));
	c.StdMark=a.StdMark;
	printf("%s %d\n",a.Stdno,a.StdMark);
}


void f(Dic *a){
	printf("\n%s\n%d\n",a->Stdno,a->StdMark);

}