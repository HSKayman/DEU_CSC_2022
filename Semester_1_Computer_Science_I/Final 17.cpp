#include<stdio.h>
int main(){
	printf("Lutfen Cumle Giriniz:"); char a[300]; scanf("%[^\n]s",a);
	int i,f=1,ctrl=1,count=0;
	for(i=0;a[i]!=0;i++)
	{
		if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
		{
			f=1;
		}else if(f!=0){
			f=0;
		}
		if(ctrl!=f){
			count++;
			ctrl=f;
		}
	}
	printf("Bu Cumlede %d adet sayi vardir.",(count/2)+1);
}
