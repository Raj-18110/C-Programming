#include<stdio.h>
void main()
{
	int n,i;
	printf("\nEnter size of the array : ");
	scanf("%d",&n);
	int ar[n];
	printf("\nEnter elements of array : \n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d :",(i+1));
		scanf("%d",&ar[i]);
	}
	int *p;
	if(!p)
		printf("\nMemory unavailable");
	p=ar;
	int k1,k2;
	printf("\nEnter k1 (<=%d): ",n);
	scanf("%d",&k1);
	printf("\nEnter k2 (<=%d): ",n);
	scanf("%d",&k2);
	printf("\nk1th element is : %d",*(p+k1-1));
	printf("\nk2th element is : %d",*(p+k2-1));
	int *p1=p+k1,*p2=p+k2;
	printf("\nThe address of k1th element is : %p",p1);
	printf("\nThe address of k2th element is : %p",p2);
	printf("\nThe difference between the address is : %d",(p2-p1)*sizeof(int));
	printf("\n");
}
