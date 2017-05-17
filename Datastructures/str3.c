#include<stdio.h>
#include<stdlib.h>
void main()
{
	char s[80];int i;
	printf("\nEnter sentence : ");
	gets(s);
	int l2=0;
	for(i=0;s[i]!='\0';i++)
		l2++;
	for(i=l2-1;i>=0;i--)
	printf("%c",s[i]);
	printf("\n");
}
