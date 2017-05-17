#include<stdio.h>
void main()
{
	int n,s1=0,s=0,i,j,k;
	printf("\nEnter size of array : ");
	scanf("%d",&n);
	int ar[n];
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d : ",i+1);
		scanf("%d",&ar[i]);
	}
	
	
	
	for(j=0;j<n;j++)
	{	
		s=ar[j];k=j;		
		while(s!=0)	
		if(ar[k]<=ar[k+1])
		{		
			s=s+ar[k+1];k++;
		}
		else if(s1<s)
		{s1=s;k++;}
		else
		{
			s=0;
		}
	}
	printf("\nThe sum is : %d",s1);
	printf("\n");

}
