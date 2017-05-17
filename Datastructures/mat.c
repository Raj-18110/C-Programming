#include<stdio.h>
#include<stdlib.h>
void rotate(int **ar,int **a,int n);
void main()
{
	int n;
	printf("\nEnter the order of the matrix : ");
	scanf("%d",&n);
	int **ar;
	int i,j;
	ar=(int**)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		ar[i]=(int*)malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("\nEnter (%d,%d)th element : ",i+1,j+1);
			scanf("%d",&ar[i][j]);
		}
	
	int **a;
	a=(int**)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		a[i]=(int*)malloc(n*sizeof(int));
	}
	rotate(ar,a,n);
	printf("\nThe resultant matrix is : \n");
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
			printf("%d  ",a[i][j]);
	printf("\n");
	}
	printf("\n");
}

void rotate(int **ar,int **a,int n)
{
	int i,j,l=0,k=0;
	for(j=0;j<n;j++)
	{
		for(i=n-1;i>=0;i--)
		{
			a[l][k++]=ar[i][j];
		}
		l++;
		k=0;
	}
}
