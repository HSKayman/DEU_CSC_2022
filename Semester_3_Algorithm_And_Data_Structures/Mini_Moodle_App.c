#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>
#define clear() printf("\033[H\033[J")
typedef struct n{
	char *name;
	struct n * hor;
	struct n * ver;
} node;
node *inputlesson(node *root,char *name);
node *deletelesson(node *root,char *name);
bool inputstudent(node *root,char *name,char *lsname);
bool deletestudent(node *root,char *lsname,char *name);
void print(node *root);
int main(){
	node * root;
	root=inputlesson(root,"BIL1001");
	root=inputlesson(root,"BIL1002");
	root=inputlesson(root,"BIL1003");
	root=inputlesson(root,"BIL1004");
	root=inputlesson(root,"BIL1005");
	print(root);
	inputstudent(root,"Ali","BIL1001");
	inputstudent(root,"Ali","BIL1001");
	inputstudent(root,"Ali","BIL1001");
	inputstudent(root,"Ali","BIL1002");
	inputstudent(root,"Ali","BIL1003");
	inputstudent(root,"sAli","BIL1003");
	inputstudent(root,"Ali","BIL1009");
	print(root);
	root=deletelesson(root,"BIL1001");
	deletestudent(root,"BIL1002","Ali");
	deletestudent(root,"BIL1003","sAli");
	root=deletelesson(root,"BIL1005");
	print(root);
/*
	clear();
	printf("\n-----------------------------Welcome To Program-----------------------------\n");
	node *root;
	while(1){
		printf("\nSelect You Want To Proces");
		printf("\n%s\n%s\n%s\n%s\n%s\n%s\n: ",
			"1-Print",
			"2-Input Lesson",
			"3-Input Student",
			"4-Delete Lesson",
			"5-Delete Student",
			"6-Exit");
		int q;
		scanf("%d",&q);
		getchar();
		if(q<1 || 6<q)
			printf("\nWrong Button\n");
		else{
			if(q==1)
				print(root);
			else if(q==2){
				printf("\n\t Name :");
				char a[30];
				scanf("%[^\n]s",a);
				root=inputlesson(root,a);
			}
			else if(q==3){
				printf("\n\t Student Name :");
				char a[30];
				scanf("%[^\n]s",a);
				printf("\n\t Lesson Name :");
				char b[30];
				getchar();
				scanf("%[^\n]s",b);
				inputstudent(root,a,b);
			}
			else if(q==4){
				printf("\n\t Name :");
				char a[30];
				scanf("%[^\n]s",a);
				root=deletelesson(root,a);
			}
			else if(q==5){
				printf("\n\t Student Name :");
				char a[30];
				scanf("%[^\n]s",a);
				printf("\n\t Lesson Name :");
				char b[30];
				getchar();
				scanf("%[^\n]s",b);
				deletestudent(root,a,b);
			}
			else{
				printf("\nGood Bye\n");
				break;
			}
		}
		printf("\n");
		sleep(1);
		clear();
		
	}
	return 0;*/
}
void print(node *root){
	printf("\n-----------------------------------------------------\n\n");
	while(root!=NULL){
		printf("=>%10s",root->name);
		node *temp=root;
		root=root->hor;
		while(root!=NULL){
			printf("->%10s",root->name);
			root=root->hor;
		}
		root=temp;
		root=root->ver;
		printf("\n");
	}
}
node *inputlesson(node *root,char *name){
	if(root==NULL){
		printf("%s",name);
		node *iroot=(node *)malloc(sizeof(node));
		iroot->name=(char *)malloc(sizeof(char)*strlen(name));
		strcpy(iroot->name,name);
		iroot->hor=NULL;
		iroot->ver=NULL;
		return iroot;
	}else{
		node *temp=root;
		while(temp->ver!=NULL)
			temp=temp->ver;
		temp->ver=(node *)malloc(sizeof(node));
		temp->ver->name=(char *)malloc(sizeof(char)*strlen(name));
		strcpy(temp->ver->name,name);
		temp->ver->hor=NULL;
		temp->ver->ver=NULL;
		return root;
	}
}
node *deletelesson(node *root,char *name){
	if(root==NULL){
		printf("\nAlready All is Delete\n");
		return root;
	}else{
		node *temp=root,*bf=root;
		bool flag=true;
		if(strcmp(temp->name,name)==0)
			flag=false;
		while(strcmp(temp->name,name)!=0){
			bf=temp;
			temp=temp->ver;
			if(temp==NULL){
				printf("\nThere Isn't Lesson Name\n");
				return root;
			}
		}
		while(temp->hor!=NULL){
			node *itemp=temp;
			while(itemp->hor!=NULL)
				itemp=itemp->hor;
			if(itemp->hor!=NULL){
				free(itemp->name);
				free(itemp);
			}else
				break;
		}
		if(flag){
			bf->ver=temp->ver;
			free(temp->name);
			free(temp);
			return root;
		}else{
			bf=root->ver;
			free(root->name);
			free(root);
			return bf;
		}
	}
}
bool inputstudent(node *root,char *name,char *lsname){
	if(root==NULL){
		printf("\nThere isn't Lesson\n");
		return false;
	}else{
		while(strcmp(root->name,lsname)!=0){
			root=root->ver;
			if(root==NULL){
				printf("\nThere Isn't Lesson Name\n");
				return false;
			}
		}
			while(root->hor!=NULL)
				root=root->hor;
			root->hor=(node *)malloc(sizeof(node));
			root->hor->name=(char *)malloc(sizeof(char)*strlen(name));
			strcpy(root->hor->name,name);
			root->hor->hor=NULL;
			root->hor->ver=NULL;
	}
	return true;
}
bool deletestudent(node *root,char *lsname,char *name){
	if(root==NULL){
		printf("\nAlready All is Delete\n");
		return false;
	}else{
		while(strcmp(root->name,lsname)!=0){
			root=root->ver;
			if(root==NULL){
				printf("\nThere Isn't Lesson Name\n");
				return false;
			}
		}
		while(strcmp(root->hor->name,name)!=0){
			root=root->hor;
			if(root->hor==NULL){
				printf("\nThere Isn't Student Name\n");
				return false;
			}
		}
		node *temp=root->hor;
		root->hor=root->hor->hor;
		free(temp->name);
		free(temp);
	}
	return true;
}