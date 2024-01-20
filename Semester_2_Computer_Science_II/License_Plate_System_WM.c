#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define clear() printf("\033[H\033[J")
typedef struct{//alt dizi
	char str[4];
	int num;
}pl;
typedef struct{//ana dizi
	int c;
	int lock;
	pl *p;
}cty;
void inpt(cty*);
void shwall(cty*,int);
void inptctrl(cty*);
void printd(cty*);
void scan(cty*);
int main(){
	cty a[82];
	FILE *cfPtr;
        if((cfPtr = fopen("stroage.dat","rb"))==NULL){
		int i;
		for(i=0;i<82;i++){//gerekli verileri sifirlama
			a[i].c=0;
			a[i].lock=0;
		}
	}else{
		fclose(cfPtr);
		scan(a);
	}
	printf("\n-----------------------------Programa Hos Geldiniz-----------------------------\n");
	while(1){//program baslangici
		printf("\n Lutfen Yapmak Istediginiz Islemi Seciniz.");
		printf("\n%s\n%s\n%s\n%s\n%s\n: ",
			"1-Kayit Edilen Plakalari Goster.",
			"2-Kayit Edilen Plakalari Sehire Gore Goster",
			"3-Yeni Plaka Kaydet",
			"4-Plaka Denetle",
			"5-Cikis");
		int q;
		scanf("%d",&q);
		if(q<1 || 5<q)
			printf("\n Yanlis Secim Yaptiniz");
		else{
			if(q==1)
				shwall(a,0);
			else if(q==2){
				while(1){
					printf("\nHangi Numarali Sehir :"); int w;
					scanf("%d",&w);
					if(w<1 || w>81){
						printf("\n Girdiginiz Numarali Sehir Bulunamadi.");
					}
					else{
						shwall(a,w);
						break;
					}
				}
			}
			else if(q==3)
				inpt(a);
			else if(q==4)
				inptctrl(a);
			else{
				printf("\nSaglicakla Kalin\n");
				break;
			}
		}
		printf("\n");
		sleep(1);
		clear();
		
	}
	printd(a);
	return 0;
}
int ctrlc(char *c){//plakanin harf kontrolu
	int i,count=0;
	for(i=0;c[i];i++){
		if(c[i]>'Z'||c[i]<'A'){
			printf("\nPlakanin Harf Kodu Buyuk Olmalidir");
			return 1;
		}
		count++;
	}
	if(count<2 || 3<count)
		return 1;
	return 0;
}
int ctrli(int c){//plakanin numerik kontrolu
	int i;
	for(i=0;c;i++)
		c/=10;
	if(i<2 || i>4)
		return 1;
	return 0;
}
int ctrll(cty *ct,int a,char *b,int c){//plakanin kayit kontrolu
	int i;
	for(i=0;i<ct[a].c;i++)
		if(ct[a].p[i].num==c && !strcmp(ct[a].p[i].str,b)){
			printf("\nBu Plaka Kayitli");
			return 1;
		}
	return 0;
}
void inptctrl(cty *ct){//plaka kontrol islemi
	printf("\nLutfen Deneyeceginiz Plakayi [Sehir/Kr. Dizini/Tam Sayi] Seklinde Giriniz:");
        char a1[10],c1[10],b[10]; scanf("%s %[^ ]s %s",a1,b,c1);
	int a=atoi(a1),c=atoi(c1);
        if((a>81 || a<1)|| ctrlc(&b[0]) || ctrli(c)||ctrll(ct,a,b,c))
        	 printf("\nMaalesef Plaka Gecerli Degil");
	else
		printf("\nPlaka Gecerli");
}
void inpt(cty *ct){//plaka giris islemi
	while(1){
		printf("\nLutfen Plakayi [Sehir/Kr. Dizini/Tam Sayi] Seklinde Giriniz:");
		char a1[10],c1[10], b[10]; scanf("%s %s %s",a1,b,c1);
		int a=atoi(a1),c=atoi(c1);
                if((a>81 || a<1)|| ctrlc(&b[0]) || ctrli(c)||ctrll(ct,a,b,c)){
			printf("\nYanlis Secim Yaptiniz.");
		}else{
			ct[a].c++;ct[0].c++;
			if(ct[a].c==1){
				ct[a].lock=10;
				ct[a].p=(pl *)malloc(ct[a].lock*sizeof(pl));
			}
			else if(ct[a].c+1==ct[a].lock){
				ct[a].lock*=10;
				ct[a].p=(pl *)realloc(ct[a].p,ct[a].lock*sizeof(pl));
			}
			strcpy(ct[a].p[ct[a].c-1].str,b);
			ct[a].p[ct[a].c-1].num=c;
			printf("\n%d %s %d Plakali Kaydiniz Basarili.",a,ct[a].p[ct[a].c-1].str,ct[a].p[ct[a].c-1].num);
			break;	
		}
	}
}
void print(cty *ct,int a){//txt ciktisi
	if(a==0){
		FILE *cfPtr;
		if((cfPtr=fopen("plakalar.txt","w"))==NULL)
                 	       printf( "Dosya acilamadi.\n" );
                else{
                        int i,j;
                        fprintf(cfPtr,"\nToplam %d Adet Plaka Var\n",ct[0].c);
                        for(i=1;i<82;i++){
	                        if(ct[i].c==0)
        	                        continue;
        	                fprintf(cfPtr,"\t%d Numarali Sehrin %d Tane Plaka Kaydi Vardir.\n",i,ct[i].c);
        	                for(j=0;j<ct[i].c;j++)
               		                 fprintf(cfPtr,"\t\t%d %s %d\n",i,ct[i].p[j].str,ct[i].p[j].num);
                	}
	                printf("\n %s Adli Dosya Olarak Kaydedildi.\n","plakar.txt");
			fclose(cfPtr);
		}
	}
	else{
		FILE *cfPtr;
		char nm[20]="plakalar_";
		char ctnm[10]="";
		char frmt[]=".txt";
	        sprintf(ctnm, "%d", a);strcat(nm,ctnm);strcat(nm,frmt);
		if((cfPtr=fopen(nm,"w"))==NULL)
			printf( "Dosya acilamadi.\n" );
		else{
			int j;
			fprintf(cfPtr,"%d Numarali Sehrin %d Tane Plaka Kaydi Vardir.\n",a,ct[a].c);
			for(j=0;j<ct[a].c;j++)
		        	fprintf(cfPtr,"\t%d %s %d\n",a,ct[a].p[j].str,ct[a].p[j].num);
                	printf("\n%s Adli Dosya Olarak Kaydedildi.\n",nm);
			fclose(cfPtr);
		}
	}
}
void shwall(cty *ct,int a){//plaka gosterim islemi
	int i,j;
	if(a==0){
		printf("\nToplam %d Adet Plaka Var\n",ct[0].c);
		for(i=1;i<82;i++){
			if(!ct[i].c)
				continue;
			printf("\t%d Numarali Sehrin %d Tane Plaka Kaydi Vardir.\n",i,ct[i].c);
			for(j=0;j<ct[i].c;j++)
				printf("\t\t%d %s %d\n",i,ct[i].p[j].str,ct[i].p[j].num);
		}
		printf("\nDosyalarin Kayit Edilmesini Ister Misiniz[E(e)/H(h)] ? : ");
                char q;
                getchar();
                scanf("%c",&q);
                if(q=='E'||q=='e')
                       print(ct,a);

	}else{	
		 printf("%d Numarali Sehrin %d Tane Plaka Kaydi Vardir.\n",a,ct[a].c);
                 for(j=0;j<ct[a].c;j++)
			printf("\t%d %s %d\n",a,ct[a].p[j].str,ct[a].p[j].num);
		 printf("\nDosyalarin Kayit Edilmesini Ister Misiniz[E(e)/H(h)] ? : ");
		 char q;
		 getchar();
		 scanf("%c",&q);
		 if(q=='E'||q=='e')
			print(ct,a);		 
      	}
}
void scan(cty *ct){//dat okuma
	FILE *cfPtr;
	if((cfPtr = fopen("stroage.dat","rb+"))==NULL)
		printf("\nKaydedilen Dosyayi Okumakta Problem Cikti.\n");
	else{
		int i,j;
		for(i=0;i<82;i++){
			fread(&ct[i].c,sizeof(int),1,cfPtr);
			fread(&ct[i].lock,sizeof(int),1,cfPtr);
			if(ct[i].lock!=0){
				ct[i].p=(pl*)malloc(ct[i].lock*sizeof(pl));
				for(j=0;j<ct[i].c;j++)
					fread(&ct[i].p[j],sizeof(pl),1,cfPtr);			
			}
		}
		fclose(cfPtr);
	}
}
void printd(cty *ct){//dat yazma
	FILE *cfPtr;
	if((cfPtr = fopen("stroage.dat","wb+"))==NULL)
		printf("\nKaydetmede Problem Cikti.\n");
	else{
		int i,j;
		for(i=0;i<82;i++){
			fwrite(&ct[i].c,sizeof(int),1,cfPtr);
			fwrite(&ct[i].lock,sizeof(int),1,cfPtr);	
			if(i!=0)
				for(j=0;j<ct[i].c;j++)
					fwrite(&ct[i].p[j],sizeof(pl),1,cfPtr);
		}
		fclose(cfPtr);
	}
}
