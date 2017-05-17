#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *right;
	struct tree *left;
}*root;


void insert(int v,struct tree **r)
{
	if((*r)==NULL)
	{
		*r=(struct tree *)malloc(sizeof(struct tree));		
		(*r)->data=v;
		(*r)->left=NULL;
		(*r)->right=NULL;
	}
	else
	{
		if((*r)->data>v)
		insert(v,&(*r)->left);
	
		else
		insert(v,&(*r)->right);
	}

}


void displaypre(struct tree *r)
{
		printf("\n   %d",r->data);
		if(r->left!=NULL)
		displaypre(r->left);
		if(r->right!=NULL)
		displaypre(r->right);

}


int search(int key,struct tree *r)
{
	int c=0;	
	if(r->data==key)
	{
		printf("\nFound\n");
		c=1;
		return c;
	}
	else if(r->data>key && r->left!=NULL)
	search(key,r->left);
	else if(r->data<key && r->right!=NULL)
	search(key,r->right);
}

void max(struct tree *root)
{
	if(root->right==NULL)
	printf("\nMaximum value is : %d",root->data);
	else
	max(root->right);
}

void min(struct tree *root)
{
	if(root->left==NULL)
	printf("\nMinimum value is : %d",root->data);
	else
	min(root->left);
}

void displayin(struct tree *r)
{
	if(r->left!=NULL)
	displayin(r->left);
	printf("\n  %d",r->data);
	if(r->right!=NULL)
	displayin(r->right);
}

void displaypost(struct tree *r)
{
	if(r->left!=NULL)
	displaypost(r->left);
	if(r->right!=NULL)
	displaypost(r->right);
	printf("\n  %d",r->data);
}

void printleaf(struct tree *root)
{
	if(root->right==NULL && root->left==NULL)
		printf("%d   ",root->data);
	else
	{
		if(root->left!=NULL)
		printleaf(root->left);
		if(root->right!=NULL)	
		printleaf(root->right);
	}
}

void printnonleaf(struct tree *root)
{
	if(root->left!=NULL || root->right!=NULL)   
	{
		printf("%d   ",root->data);
		if(root->left!=NULL)
		printnonleaf(root->left);
		if(root->right!=NULL)
		printnonleaf(root->right);
	}
	
}

void search1(struct tree *root,int key,int *c,struct tree **parent,struct tree **x)
{
	if(root->data==key)
	{
		*x=root;
		*c=1;
	}
	else if(root->data>key && root->left!=NULL)
	{
		search(key,root->left);
		*parent=root;
	}
	else if(root->data<key && root->right!=NULL)
	{
		search(key,root->right);
		*parent=root;
	}

	if(*c==0)
	printf("\nNumber not found!\n");
	else
	printf("\nNumber found\n");
}

void delete(struct tree *root,int key)
{
	struct tree *parent,*x,*xs;
	int c=0;
	parent=NULL,x=NULL,xs=NULL;
	search1(root,key,&c,&parent,&x);
	if(c==0)
	return;
	else
	{
		if(x->left==NULL && x->right==NULL)
		{
			if(parent->left==x)
			parent->left=NULL;
			else
			parent->right=NULL;
			free(x);
		}
		else if(x->left==NULL || x->right==NULL)
		{
			if(x->right==NULL)
			{
				if(parent->left==x)
				parent->left=x->left;
				else
				parent->right=x->left;
				free(x);
			}
			else if(x->left==NULL)
			{
				if(parent->left==x)
				parent->left=x->right;
				else
				parent->right=x->right;
				free(x);
			}
		}
		else if(x->left!=NULL && x->right!=NULL)
		{
			xs=x->right;
			while(xs->left!=NULL)
			{
				parent=xs;				
				xs=xs->left;
			}
			x->data=xs->data;
			if(parent->left==xs)
			parent->left=NULL;
			else
			parent->right=NULL;
			free(xs);
		}
	}
}
			
void main()
{
	int n,i,j,key;
	printf("\nEnter no. of elements : ");
	scanf("%d",&n);
	int ar[n];
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d : ",i+1);
		scanf("%d",&ar[i]);
	}
	root=0;
	for(i=0;i<n;i++)
	insert(ar[i],&root);
	printf("\nPre-order : \n");
	displaypre(root);printf("\n");
	printf("\nEnter key to search : ");
	int k;
	scanf("%d",&k);
	j=search(k,root);
	if(j!=1)
	printf("\nNot Found! \n");	
	printf("\nIn-order : \n");
	displayin(root);
	printf("\nPost-order : \n");
	displaypost(root);
	printf("\n");
	max(root);
	min(root);
	printf("\nLeaf nodes are : \n");
	printleaf(root);
	printf("\nNon-leaf nodes are : \n");
	printnonleaf(root);
	printf("\nEnter key to delete : ");
	scanf("%d",&key);
	delete(root,key);
	displaypre(root);
	printf("\n");
	
}
