#include<stdio.h>
#include<stdlib.h>
struct list
{
	int val;
	struct list *link;
};
struct list *root;

struct list *init_node()
{
	struct list *p;
	p=(struct list *)malloc(sizeof(struct list));
	return(p);
}

void create_list(int n)
{
	struct list *p;int c=0;
	p=init_node();
	if(p==NULL)
	{
		printf("\nMemory error!\n");
	}
	else
	{
		c++;
		printf("\nEnter data of element : ");
		scanf("%d",&p->val);
		root=p;
		while(c<n)
		{
			
			p=init_node();c++;
			printf("\nEnter data of element : ");
			scanf("%d",&p->val);
			p->link=root;
			root=p;
		
		}
	}
	
}

void insert_start()
{
	struct list *q;
	q=init_node();
	printf("\nEnter value to be entered : ");scanf("%d",&q->val);
	q->link=root;
	root=q;
	printf("\nElement inserted at start\n");
	
}

void insert_end()
{
	struct list *p,*q;
	p=root;
	while(p->link!=NULL)
	p=p->link;
	q=init_node();
	if(q==NULL)
	printf("\nMemory error!");
	p->link=q;
	printf("\nEnter value to be entered : ");scanf("%d",&q->val);
	q->link=NULL;
	printf("\nElement inserted at end\n");
	
}

void insert_middle(int n)
{
	int c=0,n1,i;
	struct list *p,*q,*r;
	p=root;
	while(c==0)
	{
		printf("\nEnter the position after which you want to enter your element : ");
		scanf("%d",&n1);
		if(n1>n)
		{
			printf("\nNot possible....enter again\n");
			continue;
		}
		else
		{
			c++;
			for(i=1;i<=n1-1;i++)
			p=p->link;
			r=p;
			q=init_node();
			printf("\nEnter value : ");
			scanf("%d",&q->val);
			q->link=r->link;
			p->link=q;
			printf("\nElement inserted in position %d . \n",n1);
		}
	}
	
}
			
void delete_start()
{
	printf("\nElement deleted is %d .\n",root->val);	
	root=root->link;
	printf("\nFirst element deleted\n");
}

void delete_end()
{
	struct list *p;	p=root;
	while(p->link->link!=NULL)
	p=p->link;
	printf("\nElement deleted is %d .\n",p->link->val);
	p->link=NULL;
	printf("\nLast element deleted\n");
	
}	
		
void delete_middle(int n)
{
	int n1,i;
	struct list *p,*q;	p=root;
	printf("\nEnter position of no. you want to delete : ");
	scanf("%d",&n1);
	if(n1>n)
	printf("\nNot possible\n");
	else
	{
		for(i=1;i<=n1-2;i++)
		p=p->link;
		q=p;
		p->link=q->link->link;
		printf("\nElement deleted is %d \n",q->val);	
	}
	
}

void search(int e)
{
	struct list *p;
	int c=1;
	p=root;
	while(p!=NULL)
	{
		if(p->val==e)
		printf("\nElement found in position %d . \n",c);
		p=p->link;c++;
	}
}

void display()
{
	struct list *p;
	p=root;
	while(p!=NULL)
	{
		printf("   %d",p->val);
		p=p->link;
	}
}

void main()
{
	int n,e;char ch='y';
	printf("\nEnter no. of elements you want to enter : ");
	scanf("%d",&n);
	int c;
	create_list(n);
do
{
	system("clear");
	printf("\nThe list is : \n");
	display();	
	printf("\nEnter\n1 for insert at start\n2 for insert at end\n3 for insert at middle\n4 for delete at start\n5 for delete at end\n6 for delete at middle\n7 for search\n\nEnter your choice : ");
	scanf("%d",&c);
	if(c==1)
	insert_start();
	else if(c==2)
	insert_end();
	else if(c==3)
	insert_middle(n);
	else if(c==4)
	delete_start();
	else if(c==5)
	delete_end();
	else if(c==6)
	delete_middle(n);
	else if(c==7)
	{
		printf("\nEnter element to search : ");scanf("%d",&e);search(e);
	}
	else
	printf("\nInvalid choice\n");
	printf("\nThe list is : \n");
	display();
	printf("\nDo you want to continue?(y/n) : ");
	getchar();
	scanf("%c",&ch);
}
while(ch=='y');
}
	
	
	














	
