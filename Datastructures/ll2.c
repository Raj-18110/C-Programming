#include<stdio.h>
#include<stdlib.h>
struct list
{
	int val;
	struct list *link;
	struct list *link1;
};
struct list *root,*end;

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
		scanf("%d",&p->val);p->link=NULL;
		root=p;end=p;
		while(c<n)
		{
			
			p=init_node();c++;
			printf("\nEnter data of element : ");
			scanf("%d",&p->val);
			p->link=root;root->link1=p;p->link1=NULL;
			root=p;
		
		}
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


void displayend()
{
	struct list *p;
	p=end;
	while(p!=NULL)
	{
		printf("   %d",p->val);
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
	printf("\n");
}
