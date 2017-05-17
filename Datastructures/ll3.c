#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *link;
	struct list *link1;
}*root,*end;

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
		scanf("%d",&p->data);p->link=NULL;
		root=p;end=p;
		while(c<n)
		{
			
			p=init_node();c++;
			printf("\nEnter data of element : ");
			scanf("%d",&p->data);
			p->link=root;root->link1=p;p->link1=NULL;
			root=p;
		
		}
	}
	
}
struct list *endlist(struct list *p)
{
	struct list *q;q=root;	
	while(q->link!=p)
		q=q->link;
	return q;
}
void reverse()
{
	struct list *t1,*t2,*p;int t;
	while(p->link!=NULL)
		p=p->link;

	t1=root;t2=p;
	while(t2!=t1 || t2->link==t1)
	{
		t=t1->data;
		t1->data=t2->data;
		t2->data=t;
		t1=t1->link;
		while(p->link!=t2)
			p=p->link;
		t2=p;
	}
}

void display()
{
	struct list *p;
	p=root;
	while(p!=NULL)
	{
		printf("   %d",p->data);
		p=p->link;
	}
}

void displayend()
{
	struct list *p;
	p=end;
	while(p!=NULL)
	{
		printf("   %d",p->data);
		p=p->link1;
	}
}

void main()
{
	int n,e;char ch='y';
	printf("\nEnter no. of elements you want to enter : ");
	scanf("%d",&n);
	int c;
	create_list(n);
	printf("\nThe actual list is : \n");
	display();	
	printf("\nThe reversed list is : \n");
	displayend();
}	
	
