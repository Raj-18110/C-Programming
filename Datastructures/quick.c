#include<stdio.h>
void quicksort(int ar[],int low,int high,int i);
int partition(int ar[],int low,int high,int i);
void swap(int ar[],int n1,int n2);
int s=0,c=0,d=0;
void main()
{
	int n,i,j,k;	
	printf("\nEnter no. of elements you want to enter in the array : ");
	scanf("%d",&n);
	int ar[n],a[n];
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d : ",i+1);
		scanf("%d",&ar[i]);
	}
	int low=0,high=n-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)a[j]=ar[j];		
		quicksort(a,low,high,i);
		printf("\nNo. of comparisons for pivot=%d are : %d",i,c);
		printf("\nNo. of swappings for pivot=%d are : %d",i,s);
		printf("\nSorted array is : \n");
		for(k=0;k<n;k++)printf("  %d",a[k]);
		c=0;s=0,d=0;
		
	}
		
}

void quicksort(int ar[],int low,int high,int i)
{
	int pivot;	
	if(high>low)
	{
		pivot=partition(ar,low,high,i);
		quicksort(ar,low,pivot-1,i);
		quicksort(ar,pivot+1,high,i);
	}
}

int partition(int ar[],int low,int high,int i)
{
	int left,right,pivot;
	int pivot_item;
	left=low;
	if(d==0)
	{pivot=low+i;d++;}
	else
	pivot=low;
	pivot_item=ar[pivot];
	right=high;
	while(left<right)
	{
		while(ar[left]<=pivot_item)
		{
			left++;c++;
		}
		while(ar[right]>pivot_item)
		{
			right--;c++;
		}
		if(left<right)
		{
			swap(ar,left,right);s++;
		}
	}
	swap(ar,pivot,right);s++;
	return right;
}

void swap(int ar[],int n1,int n2)
{
	int t;
	t=ar[n1];
	ar[n1]=ar[n2];
	ar[n2]=t;
}
