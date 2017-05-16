#include<stdio.h>
int k,n,i,j,s;
int a[100000];
void right_check(int left,int right);
int  mid_check1(int mid,int left);
int mid_check2(int mid,int left,int right);
void quicksort(int first,int last);

 void quicksort(int first,int last){
    int pivot,temp1;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(a[i]<=a[pivot]&&i<last)
                 i++;
             while(a[j]>a[pivot])
                 j--;
             if(i<j){
                 temp1=a[i];
                  a[i]=a[j];
                  a[j]=temp1;
             }
         }

         temp1=a[pivot];
         a[pivot]=a[j];
         a[j]=temp1;
         quicksort(first,j-1);
         quicksort(j+1,last);

    }
}

int  mid_check1(int mid,int left)	
{
while(mid>=left)
{
if((a[mid]-a[left])>k)
{
mid=mid-1;
}
else{
break;}
}
return mid;
}

int  mid_check2(int mid,int left,int right)
{

while(mid<=right)
{
if((a[mid]-a[left])<=k)
{
mid=mid+1;
}
else
{break;}
}
return mid;

}

void transmission(int left,int right)
{
int mid;
//printf("Left value: %d\n Right value: %d\n",left,right);
mid=(left+right)/2;
mid=mid_check2(mid,left,right);
mid=mid_check1(mid,left);
//printf("Value of mid is %d\n",mid);

while(right>=mid)
{
if((a[right]-a[mid])>k)
{
right=right-1;
}
else 
{break;}
}
//printf("Value of right is :%d\n",right);
s=s+1;
left=right+1;
right=n;
if(left==right && left==n  )
{
s=s+1;
left=n+1;
}
if(left>n)
{printf("%d",s);}
else
{
transmission(left,right);
}
}
int main()
{
int left,right,temp;
scanf("%d%d",&n,&k);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);


quicksort(1,n);

/*for(i=1;i<=n;i++){
for(j=i+1;j<=n;j++)
{

if(a[i]>a[j])
{
temp=a[j];
a[j]=a[i];
a[i]=temp;
}
}
}*/
//for(i=1;i<=n;i++)
//printf("%d ",a[i]);
left=1;right=n;
transmission(left,right);
    return 0;
}


