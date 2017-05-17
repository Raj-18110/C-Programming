#include<stdio.h>
void main()
{
	int i,j,l=0,c=0,k2,k1,n1,n2;
	printf("\nEnter no. of rows : ");
	scanf("%d",&n1);
	printf("\nEnter no. of columns : ");
	scanf("%d",&n2);
	int a[n1][n2];
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			printf("\nEnter element (%d,%d) : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	int ar[100];
	
for(l=0,k1=n1-1,k2=n2-1;l<=k1||l<=k2;l++,k1--,k2--)
{
	for(j=l;j<=k2;j++)
		ar[c++]=a[l][j];
	for(i=l+1;i<=k1;i++)
		ar[c++]=a[i][k2];
	for(j=k2-1;j>=l;j--)
		ar[c++]=a[k1][j];
	for(i=k1-1;i>l;i--)
		ar[c++]=a[i][l];

}

printf("\n\nThe Original Matrix is : \n");
for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			printf("%d   ",a[i][j]);
		}
		printf("\n");
	}
c=0;

printf("\n\nThe Spiral Matrix is : \n");
for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			printf("%d   ",ar[c++]);
		}
		printf("\n");
	}
printf("\n");
}	
