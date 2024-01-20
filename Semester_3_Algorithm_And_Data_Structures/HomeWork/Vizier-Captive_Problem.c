#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>
#include<string.h>
#include<unistd.h>
#define clear() printf("\033[H\033[J")
///////////// Isimli Vezir-Esir
typedef struct n{
	char *data;
	struct n *next;
}LL;
LL *input(LL * root,char *x){
	if(root==NULL){
		root=(LL *)malloc(sizeof(LL));
		root->next=root;
		root->data=(char *)malloc(sizeof(char)*(strlen(x)+1));
		strcpy(root->data,x);
		return root;
	}
	LL *motroot=root;	
	while(root->next!=motroot)
		root=root->next;
	root->next=(LL *)malloc(sizeof(LL));
	root->next->data=(char *)malloc(sizeof(char)*(strlen(x)+1));	
	strcpy(root->next->data,x);
	root->next->next=motroot;
	return motroot;
}
void proc(LL* root,unsigned x,int y){
	int j=0;
	while(y>1){
		int i=1;
		while(i<x-1){
			root=root->next;
			++i;
		}
		if(x==1){
			LL*temp=root;
			LL*end=root;
			while(end->next!=root){
				end=end->next;
			}
			end->next=root->next;
			root=root->next;
			printf("\n->%d). %s %s.",++j,temp->data,"Olduruldu.");
			free(temp);
		}else{
			LL *temp=root->next;
			root->next=temp->next;
			root=root->next;
			printf("\n->%d). %s %s.",++j,temp->data,"Olduruldu.");
			free(temp);
		}
		--y;
	}
	printf("\nYasayan %s\n",root->data);
	getchar();
	printf("\nGecmek Icin Bir Tusa Basiniz.");
	getchar();
}
////// Indexli Vezir Esir
typedef struct s{
	int data;
	struct s *next;
}LL2;
LL2* input2(LL2 * root,int x){
	if(root==NULL){
		root=(LL2 *)malloc(sizeof(LL2));
		root->next=root;
		root->data=x;
		return root;
	}
    LL2 *motroot=root;
	while(root->next!=motroot)
		root=root->next;
	root->next=(LL2 *)malloc(sizeof(LL2));
	root->next->data=x;
	root->next->next=motroot;
	return motroot;
}
void proc2(LL2* root,unsigned x,int y){
	int j=0;
	while(y>1){
		int i=1;
		while(i<x-1){
			root=root->next;
			++i;
		}
		if(x==1){
			LL2*temp=root;
			LL2*end=root;
			while(end->next!=root){
				end=end->next;
			}
			end->next=root->next;
			root=root->next;
			printf("\n->%d). %d indexli Esir %s.",++j,temp->data,"Olduruldu.");
			free(temp);
		}else{
			LL2*temp=root->next;
			root->next=temp->next;
			root=root->next;
			printf("\n->%d). %d indexli Esir %s.",++j,temp->data,"Olduruldu.");
			free(temp);
		}
		--y;
	}
	printf("\nYasayan %d Indexli Esir\n",root->data);
	getchar();
	printf("\nGecmek Icin Bir Tusa Basiniz.");
	getchar();
}
int main(){
	clear();
	printf("\n-----------------------------Programa Hos Geldiniz-----------------------------\n");
	while(true){//program baslangici
		printf("\n Lutfen Yapmak Istediginiz Islemi Seciniz.");
		printf("\n%s\n%s\n%s\n: ",
			"1-Esiri Isimle Kaydet",
			"2-Esiri Indexle Kaydet",
			"3-Cikis");
		int q; char q23[10];
		scanf("%[^\n]s",q23);
		q=atoi(q23);
		if(q<1 || 3<q){
			printf("\n Yanlis Secim Yaptiniz");
			getchar();
		}
		else{
			if(q==1){
				while(true){
					printf("\nKac Tane Esir Var :");
					int q3; char q3w[10];
					getchar();
					scanf("%[^\n]s",q3w);
					q3=atoi(q3w);
					if(q3<1){
						printf("\n Yanlis Secim Yaptiniz");
						getchar();
					}
					else{
						LL *p=NULL;
						int q4=q3;
						int co=0;
						while(0<q3){
							char name[30];
							printf("\n %d. Isim :",++co);
							getchar();
							scanf("%[^\n]s",name);
							p=input(p,name);
							--q3;
						}
						while(true){
							printf("\nVezirin Soyledigi Sayi Kac :");
							unsigned vezir; char vezirw[10];
							getchar();
							scanf("%[^\n]s",vezirw);
							vezir=(unsigned)atoi(vezirw);
							if(vezir<1){
								printf("\n Yanlis Secim Yaptiniz");
								getchar();
							}
							else{
								proc(p,vezir,q4);
								break;
							}
						}
						break;
					}
				}
			}
			else if(q==2){
				while(true){
					printf("\nKac Tane Esir Var :");
					int q3;char q3w[10];
					getchar();
					scanf("%[^\n]s",q3w);
					q3=atoi(q3w);
					if(q3<1){
						printf("\n Yanlis Secim Yaptiniz");
						getchar();
					}
					else{
						LL2 *p=NULL;
						int q4=q3;
						int count=0;
						while(0<q3){
							p=input2(p,++count);
							--q3;
						}
						while(true){
							printf("\nVezirin Soyledigi Sayi Kac :");
							unsigned vezir;char vezirw[10];
							getchar();
							scanf("%[^\n]s",vezirw);
							vezir=(unsigned)atoi(vezirw);
							if(vezir<1){
								printf("\n Yanlis Secim Yaptiniz");
								getchar();
							}
							else{
								proc2(p,vezir,q4);
								break;
							}
						}
						break;
					}
				}
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