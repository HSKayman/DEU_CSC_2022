#include<stdio.h>
int main(){
	int a; 	char c;
	q: printf("Ocak:1 \t \t Subat:2 \t Mart:3 \nNisan:4 \t Mayis:5 \t Haziran:6 \nTemmuz:7 \t Agustos:8 \t Eylul:9 \nEkim:10 \t Kasim:11 \t Aralik:12\n");
	printf("\nLutfen dogdugunuz ayin numarasini seciniz: "); scanf("%d",&a);
    if(a==1){
    	getchar();
		f: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Yay"); break;
    		case 'S': printf("Kova"); break;
    		default : printf("yanlis islem yaptiniz"); goto f;
		}
	}
	else if(a==2){
    	getchar();
		g: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Kova"); break;
    		case 'S': printf("Balik"); break;
    		default : printf("yanlis islem yaptiniz"); goto g;
		}
	}
	else if(a==3){
    	getchar();
		h: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Balik"); break;
    		case 'S': printf("Koc"); break;
    		default : printf("yanlis islem yaptiniz"); goto h;
		}
	}
	else if(a==4){
    	getchar();
		j: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Koc"); break;
    		case 'S': printf("Buffalo"); break;
    		default : printf("yanlis islem yaptiniz"); goto j;
		}
	}
	else if(a==5){
    	getchar();
		j1: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Buffalo"); break;
    		case 'S': printf("Ikizler"); break;
    		default : printf("yanlis islem yaptiniz"); goto j1;
		}
	}
	else if(a==6){
    	getchar();
		j2: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Ikizler"); break;
    		case 'S': printf("Ucuzler"); break;
    		default : printf("yanlis islem yaptiniz"); goto j2;
		}
	}
	else if(a==7){
    	getchar();
		j3: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Ucuzler"); break;
    		case 'S': printf("Aslan"); break;
    		default : printf("yanlis islem yaptiniz"); goto j3;
		}
	}
	else if(a==8){
    	getchar();
		j4: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Aslan"); break;
    		case 'S': printf("Kaplan"); break;
    		default : printf("yanlis islem yaptiniz"); goto j4;
		}
	}
	else if(a==9){
    	getchar();
		j5: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Kaplan"); break;
    		case 'S': printf("Basak"); break;
    		default : printf("yanlis islem yaptiniz"); goto j5;
		}
	}
	else if(a==10){
    	getchar();
		j6: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Basak"); break;
    		case 'S': printf("Terazi"); break;
    		default : printf("yanlis islem yaptiniz"); goto j6;
		}
	}
	else if(a==11){
    	getchar();
		j7: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("terazi"); break;
    		case 'S': printf("Oglak"); break;
    		default : printf("yanlis islem yaptiniz"); goto j7;
		}
	}
	else if(a==12){
    	getchar();
		j8: printf("\n20'sinden Once mi sonra mi? [O/S]"); scanf("%c",&c);
		switch(c){
    		case 'O': printf("Oglak"); break;
    		case 'S': printf("Yay"); break;
    		default : printf("yanlis islem yaptiniz"); goto j8;
		}
	}
	else{
		printf("yanlis islem yaptiniz"); goto q;
	}
	printf("\n BY BY");
}
