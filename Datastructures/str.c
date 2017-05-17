#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int i,l1=0,l2=0,l3=0,l4=0;
	char name[30],roll[30],branch[30];
	printf("\nEnter name : ");
	gets(name);
	printf("\nEnter roll : ");
	gets(roll);
	printf("\nEnter branch : ");
	gets(branch);
	for(i=0;name[i]!='\0';i++)
	l1++;
	for(i=0;roll[i]!='\0';i++)
	l2++;
	for(i=0;branch[i]!='\0';i++)
	l3++;
	char net[40];
	for(i=0;i<l1;i++)
	net[l4++]=name[i];
	net[l4++]=' ';
	for(i=0;i<l2;i++)
	net[l4++]=roll[i];
	net[l4++]=' ';
	for(i=0;i<l3;i++)
	net[l4++]=branch[i];
	net[l4++]=' ';
	printf("\nThe resultant string is : ");
	for(i=0;i<l4;i++)
	printf("%c",net[i]);
	printf("\n");
}
