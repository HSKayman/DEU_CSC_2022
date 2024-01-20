#include<stdio.h>
int main()
{
char c[200];
printf("Sifrelenmesini istediginiz metni giriniz.==>"); scanf("%[^\n]s",c);
int i;
for(i=0;i<199;i++)
{
	if(c[i]!='\0')
	{
		
		if(c[i]=='z')
		{
			c[i]='a';	
		}else
			c[i]++;
	}
}
printf("Sifrelenmis hali %s\n\n\n",c);

for(i=0;i<199;i++)
{
	if(c[i]!='\0')
	{
		
		if(c[i]=='a')
		{
			c[i]='z';	
		}
		else
			c[i]--;
	}
}
printf("Sifrelenmemis hali %s\n\n\n",c);	
}
