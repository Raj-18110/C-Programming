#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,k,j=-1;
	char s[80];
	printf("\nEnter sentence : ");
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ')
		{
			for(k=i-1;k>=j+1;k--)
			printf("%c",s[k]);
			printf(" ");
			j=i;
		}
	}
	for(k=i-1;k>=j+1;k--)
			printf("%c",s[k]);
			printf(" ");
	
	printf("\n");
}
