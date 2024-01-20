#include <stdio.h>

int main(){
	int f[2][5];
	float q;
	char s[1];
	for( int i=0;i<2;i++){
		for(int j=0;j<5;j++){
			printf("Lutfen %d. fabrikanin %d. iscisinin maasi :",i+1,j+1); scanf("%d",&f[i][j]);
			q1: printf("Bu maasa zam yapilsin mi [E/H]: "); getchar();
			switch(getchar()){
			case 'E':{
				printf("Yuzden kac zam yapilsin : "); scanf("%f",&q);
				f[i][j]+=(float)f[i][j]*(float)((float)q/100);
				 break;
			case 'H': printf("%d. fabrikanin %d. iscisine Zam yapilmadi.\n",i+1,j+1); break;			
			default: printf("lutfen tekrar deneyiniz.\n"); goto q1;
			}
		}
	}
	}
	printf("\n\n\n\n\n\n");
	int i=0;
	while(i<2){
	int j=0;
		while(j<5){
			printf("\n%d. fabrikanin %d. iscinin maasi :%d\n",i+1,j+1,f[i][j]);
			j++;
		}
	i++;
	}
	
	
	
}