#include<stdio.h>
#include<stdlib.h>
//Level 5 size a uyumlu normal que


int main(){
	que *s=create();
	int i;
	for(i=0;i<5;++i)
		enque(s,i);
	print(s);
	for(i=0;i<3;++i)
		deque(s);
	print(s);
	for(i=0;i<8;++i)
		enque(s,i*15);
	for(i=0;i<5;++i)
		enque(s,i);
	for(i=0;i<5;++i)
		enque(s,i);
	print(s);
	for(i=0;i<3;++i)
		deque(s);
	for(i=0;i<3;++i)
		deque(s);
	for(i=0;i<3;++i)
		deque(s);
	for(i=0;i<3;++i)
		deque(s);
	for(i=0;i<3;++i)
		deque(s);
	print(s);
}
/*//Level 1///
int ar[10];
int end=0;
int start=0;
void print(){
	int i;
	printf("\n\n--------------------\n\n");
	for(i=start-1;i>=end;--i)
		printf("%d\n",ar[i]);
}
void enque(int x){
	if(start<10){
		ar[start++]=x;
	}else{
		printf("\nListe dolu veya kullanim hakki bitmistir.\n");
	}
}
int deque(){
	if(end!=start){
		return ar[end++];
	}else{
		printf("\nListe Bos aq\n");
		return -1;
	}
}*/

/*//Level 2///
int ar[10],start=0;
void print(){
	int i;
	printf("\n\n--------------------\n\n");
	for(i=start-1;i>-1;--i)
		printf("%d\n",ar[i]);
}
void enque(int x){
	if(start<10){
		ar[start++]=x;
	}else{
		printf("\nListe dolu veya kullanim hakki bitmistir.\n");
	}
}
int deque(){
	if(0<start){
		int x=ar[0],i;
		for(i=0;i<start;i++)
			ar[i]=ar[i+1];
		--start;
		return x;
	}else{
		printf("\nListe Bos aq\n");
		return -1;
	}
}*/

/*//Level 3///
typedef struct{
	int ar[10];
	int start;
} que;

que *create(){
	que *a=(que *)malloc(sizeof(que));
	a->start=0;
	return a;
}
void print(que *a){
	int i;
	printf("\n\n--------------------\n\n");
	for(i=a->start-1;i>-1;--i)
		printf("%d\n",a->ar[i]);
}
void enque(que *a,int x){
	if(a->start<10){
		a->ar[a->start++]=x;
	}else{
		printf("\nListe dolu veya kullanim hakki bitmistir.\n");
	}
}
int deque(que *a){
	if(0<a->start){
		int x=a->ar[0],i;
		for(i=0;i<a->start;++i)
			a->ar[i]=a->ar[i+1];
		--a->start;
		return x;
	}else{
		printf("\nListe Bos aq\n");
		return -1;
	}
}*/

/*//Level 4///
typedef struct{
	int ar[10];
	int size;
	int end;
	int start;
}que;

que *create(){
	que *a=(que *)malloc(sizeof(que));
	a->start=0;
	a->size=0;
	a->end=0;
	return a;
}
void print(que *a){
	printf("\n\n--------------------\n\n");
	int i=0,j=a->start-1;
	while(i<a->size){      
		if(j==-1)
			j=9;
		printf("\n%d",a->ar[j]);
		++i;
		j=(j-1)%10;
	}
}
void enque(que *a,int x){
	if(a->size<10){
		a->ar[a->start]=x;
		a->start=(a->start+1)%10;
		++a->size;
	}else{
		printf("\nListe dolu veya kullanim hakki bitmistir.\n");
	}
}
int deque(que *a){
	if(0<a->size){
		int x=a->ar[a->end];
		a->end=(a->end+1)%10;
		--a->size;
		return x;
	}else{
		printf("\nListe Bos aq\n");
		return -1;
	}
}*/