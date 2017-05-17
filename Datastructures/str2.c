#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,k,j=-1,c=0,d,l2=0;
	char s[80];
	printf("\nEnter sentence : ");
	gets(s);
	char a[40];
	printf("\nEnter sentence to check : ");
	gets(a);
		for(i=0;a[i]!='\0';i++)
		l2++;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==a[0])
		{
			j=i;			
			for(k=0;k<l2;k++)
			{
				if(s[j++]!=a[k])
				break;
			}		
			if(k==l2)
			{
			c=1;
			d=i;
			}
		}
	}
	if(c==1)
	printf("\nSubstring found in position %d\n",d+1);
	else
	printf("\nSubstring not found\n");
}
