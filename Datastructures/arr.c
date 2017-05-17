 #include<stdio.h>
int set(int A[],int B[],int C[],int D[],int n1,int n2,int n3);
void main()
{
	int n1,n2,n3,i;
	printf("\nEnter size of the array A : ");
	scanf("%d",&n1);
	printf("\nEnter size of the array B : ");
	scanf("%d",&n2);
	printf("\nEnter size of the array C : ");
	scanf("%d",&n3);
	int A[n1];
	int B[n2];
	int C[n3];
	system("clear");
	printf("\nEnter elements of array A : \n");
	for(i=0;i<n1;i++)
	{
		printf("\nEnter element %d :",(i+1));
		scanf("%d",&A[i]);
	}
	system("clear");
	printf("\nEnter elements of array B : \n");
	for(i=0;i<n2;i++)
	{
		printf("\nEnter element %d :",(i+1));
		scanf("%d",&B[i]);
	}
	system("clear");
	printf("\nEnter elements of array C : \n");
	for(i=0;i<n3;i++)
	{
		printf("\nEnter element %d :",(i+1));
		scanf("%d",&C[i]);
	}
	
	int D[100];	
	int c;
	c=set(A,B,C,D,n1,n2,n3);
	if(c==0)
	printf("\nNULL SET\n");
	else
	{
	printf("\nThe elements of array D are \n");
	for(i=0;i<c;i++)
	printf("  %d",D[i]);
	printf("\n");
	}
}

int set(int A[],int B[],int C[],int D[],int n1,int n2,int n3)
{
	int z=0,d=0,i,j,c=0;
	int E[100];
	for(i=0;i<n1;i++)
	E[z++]=A[i];
	for(i=0;i<n2;i++)
	{
		for(j=0;j<z;j++)
		{
			if(B[i]==E[j])
			c++;
		}
		if(c==0)
		E[z++]=B[i];
		c=0;
	}
	for(i=0;i<n3;i++)
	{
		for(j=0;j<z;j++)
		{
			if(C[i]==E[j])
			D[d++]=C[i];
		}
	}
	return (d);
}
