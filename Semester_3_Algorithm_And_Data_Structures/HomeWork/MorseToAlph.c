//Dahil Edilen Kutuphaneler
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>
#include<string.h>
#include<unistd.h>
#define clear() printf("\033[H\033[J")
//Gerekli Protipler
typedef struct n{
	struct n *right;
	char dataalpha;
	char *datamorse;
	struct n *left;
}tree;
tree * create();
void Converting(tree *);
void travel(tree *,int );
int main(){
	tree *m=create();
	clear();
	printf("\n-----------------------------Programa Hos Geldiniz-----------------------------\n");
	while(true){//program baslangici
		printf("\n Lutfen Yapmak Istediginiz Islemi Seciniz.");
		printf("\n%s\n%s\n%s\n: ",
			"1-Ceviri Yap",
			"2-Agaci Goster",
			"3-Cikis");
		int q;
		scanf("%d",&q);
		if(q<1 || 3<q)
			printf("\n Yanlis Secim Yaptiniz");
		else{
			if(q==1){
				Converting(m);
			}
			else if(q==2){
				printf("\n");
				clear();
				printf("\n Lutfen Yapmak Istediginiz Islemi Seciniz.");
				printf("\n%s\n%s\n%s\n:",
				"1-Agaci PreOrder Goster",
				"2-Agaci InOrder Goster",
				"3-Agaci PostOrder Goster");
				int ww;
				scanf("%d",&ww);
				if(ww<1 || 3<ww)
					printf("\n Yanlis Secim Yaptiniz");
				else if(ww==1)
					travel(m,0);
				else if(ww==2)
					travel(m,1);
				else
					travel(m,2);
				getchar();
				printf("\nMenuye Gitmek Icin Herhangi Bir Tusa Basiniz!!!\n");
				getchar();
			}
			else if(q==3){
				printf("\nSaglicakla Kalin\n");
				break;
			}
		}
		printf("\n");
		sleep(1);
		clear();
	}
}
//Gerekli Protipler
typedef struct s{
	char data;
	struct s *next;
}node;
node * enque(node *n, char x);
char deque(node **nd);
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////// Convert Islemleri
void findM(tree *a,node *n,char *x){//Mors Aramasi Morstan Harf Icin
	if(a==NULL)
		return;
	char y=deque(&n);
	if(y==-1)
		*x=a->dataalpha;
	else if(y=='-')
		findM(a->right,n,x);
	else
		findM(a->left,n,x);
	return;
}
void MorsetoAlpha(tree *m,char *a){//Morstan Harf Alfabesine Donusturme
	node *n=NULL;
	short int i=0;
	char *y=(char *)malloc(sizeof(char));
	for(i=0;i<strlen(a);++i){
		if(a[i]==' '){
			findM(m,n,y);
			printf("%c",*y);
			if(i+1<strlen(a))
				if(a[i+1]==' '){
					printf(" ");
					i+=1;
				}
			n=NULL;
		}else{
			n=enque(n,a[i]);
		}
	}
	findM(m,n,y);
	printf("%c",*y);
	return;
}
void find(tree *a,char x,char *y){//Harf Aramasi Harften Mors Icin
	if(a!=NULL){
		if(a->dataalpha==toupper(x))
			strcpy(y,a->datamorse);
		find(a->right,x,y);
		find(a->left,x,y);
	}else
		return;
}
void AlphatoMorse(tree *m,char *a){//Harften Mors Alfabesine Donusturme
	short int x=0;
	for(x=0;x<strlen(a);++x){
		char *y=(char *)malloc(sizeof(char)*8);
		find(m,a[x],y);
		if(*y==' ')
			printf("%s",y);
		else
			printf("%s ",y);
	}
}
void Converting(tree *m){//Scanf Yeri Ve Mors to Harf Harf to Mors Karar Verme
	getchar();
	clear();
	char *a=malloc(sizeof(char)*100);
	printf("\n\n%s\n%s\n%s\n"
	   ,"Cevrilecek Metnin Mors Alfabesi Veya Buyuk-Kucuk "
		,"Latin Alfabesi Belirtmeksizin Metni Girebilirsiniz."
		,"Cevrilecek Metin :");
	scanf("%[^\n]s",a); 
	if(a[0]=='-'||a[0]=='.')
		MorsetoAlpha(m,a);
	else
		AlphatoMorse(m,a);
	getchar();
	printf("\nMenuye Gitmek Icin Herhangi Bir Tusa Basiniz!!!\n");
	getchar();
	return;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  Agac Islemleri
///////////////////////////////////////////////////////////////////////////////
tree * input(tree *a, char alpha,char *morse,int c){
	if(a==NULL){
		tree *node=(tree *)malloc(sizeof(tree));
		node->dataalpha=alpha;
		node->datamorse=(char *)malloc(sizeof(char)*strlen(morse));
		strcpy(node->datamorse,morse);
		node->right=NULL;
		node->left=NULL;
		return node;
	}else{
		if(morse[c]=='-')
			a->right=input(a->right,alpha,morse,c+1);
		else
			a->left=input(a->left,alpha,morse,c+1);
		return a;
	}
}
tree * create(){
	tree *m=NULL;
	m=input(m,' '," ",0);
	m=input(m,'E',".",0);
	m=input(m,'T',"-",0);
	m=input(m,'I',"..",0);
	m=input(m,'A',".-",0);
	m=input(m,'N',"-.",0);
	m=input(m,'M',"--",0);
	m=input(m,'S',"...",0);
	m=input(m,'U',"..-",0);
	m=input(m,'R',".-.",0);
	m=input(m,'W',".--",0);
	m=input(m,'D',"-..",0);
	m=input(m,'K',"-.-",0);
	m=input(m,'G',"--.",0);
	m=input(m,'O',"---",0);
	m=input(m,'H',"....",0);
	m=input(m,'V',"...-",0);
	m=input(m,'F',"..-.",0);
	m=input(m,'L',".-..",0);
	m=input(m,'P',".--.",0);
	m=input(m,'J',".---",0);
	m=input(m,'B',"-...",0);
	m=input(m,'X',"-..-",0);
	m=input(m,'C',"-.-.",0);
	m=input(m,'Y',"-.--",0);
	m=input(m,'Z',"--..",0);
	m=input(m,'Q',"--.-",0);
	return m;
}
void travel(tree *a,int c){
	if(a==NULL)
		return;
	if(c==0){
		printf("%c",a->dataalpha);
		travel(a->left,c);
		travel(a->right,c);
	}else if(c==1){
		travel(a->left,c);
		printf("%c",a->dataalpha);
		travel(a->right,c);
	}else{
		travel(a->left,c);
		travel(a->right,c);
		printf("%c",a->dataalpha);
	}
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  Que Islemleri
///////////////////////////////////////////////////////////////////////////////
node * enque(node *n, char x){
	if(n==NULL){
		n=(node *)malloc(sizeof(node));
		n->data=x;
		n->next=NULL;
		return n;
	}else{
		node *n2=NULL;
		n2=enque(n2,x);
		n2->next=n;
		return n2;
	}
}
char deque(node **nd){
	node *n=*nd;
	if(n==NULL){
		return -1;
	}else if(n->next==NULL){
		char x=n->data;
		*nd=NULL;
		free(n);
		return x;
	}else{
		while(n->next->next!=NULL)
			n=n->next;
		char x=n->next->data;
		free(n->next);
		n->next=NULL;
		return x;
	}
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////