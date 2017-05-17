#include<stdio.h>
  struct stack
{
  int content[100];
  int top;
};
struct stacks;
int full;
int empty;
int pop;
void push()
void main()
{
s.top=-1;
int i,n;
int fiag;
while(1)
{
printf("enter your option");
printf("1-emptystack,2-fullstack,3-push,4-pop");
scanf("%d,&n");
}
switch(n)
{
case 1:
{
if(is empty())
printf("stack is empty");
break;
}  
case 2:
{
if(is full())
printf("stack is full");
break;
}  
case 3:
{
push();
break;
}
case 4:
{
pop();
break;
}
}
printf("enter '1' to continue");
scanf("%d",&fiag);
if(flag==1)
continue;
else
break;
}
  void push()
     int x;
{
   if(is full())
     printf("push operation is not possible");
   else
{     
     printf("enter the elements to push");
   s.top++;
   s.content[s.top]=x;
}
}
   void pop()
     {
      if(is empty())
printf("pop operation is not possible");       
else
return(s.content[s.top])
s.top--;
}
int is empty()
{
if(s.top==-1)
return 1;
else
return(0);
int is full()
{
if(s.top==99)
return 1;
else
return(0);
}
for(i=0,i<2,i++)
{
printf("%d",s.content[s.top]);
s.top--:
}                                                                                                                                                                                
