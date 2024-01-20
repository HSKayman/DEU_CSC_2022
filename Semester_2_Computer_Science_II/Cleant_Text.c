#include<stdio.h>
#include<stdlib.h>
int HarfMi(int x);
int karakterSil(char *in,char *del);
int main(){
	char in[102],del[12];
	scanf("%[^\n]s",in);
	getchar();
	scanf("%[^\n]s",del);
	int a=karakterSil(in,del);
	printf("%d\n%s\n",a,in);
}
int HarfMi(int x){
	if(('a'<=x && x<='z')||('A'<=x &&x<='Z'))
		return 1;
	return 0;
}
int karakterSil(char *in,char *del){
	int count=0,i,j,k;
	for(i=0;*(del+i);i++){
		for(j=0;*(in+j);j++){
			if(HarfMi(*(in+j))){
				if(*(del+i)==*(in+j)||*(in+j)==(*(del+i)+('a'-'A'))||*(in+j)==(*(del+i)-('a'-'A'))){
					count++;
					for(k=j;*(in+k);k++)
						*(in+k)=*(in+k+1);
					j--;
				}
			}else if(*(del+i)==*(in+j)){
				count++;
				for(k=j;*(in+k);k++)
					*(in+k)=*(in+k+1);
				j--;
			}	
		}
	}
	return count;
}
