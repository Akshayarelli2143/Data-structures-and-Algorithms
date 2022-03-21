#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node  *right;
}*root=NULL;
//.............................................................................................................................
void insert()
{
	int x;
	struct node *t,*r,*p;
	t=(struct node *)malloc(sizeof(struct node));
	if(root==NULL)//first data to be fillled
	{
		printf("Enter  Root  data:\n");
		scanf("%d",&x);
		t->data=x;
		t->left=t->right=NULL;
		root=t;
	}
	else
	{
		printf("Enter the data:\n");
		scanf("%d",&x);
		t->data=x;
		t->left=t->right=NULL;
		p=root;
		while(p!=NULL)
		{
			r=p;;
			if(t->data>p->data){
				p=p->right;
			}
			else
			{
				p=p->left;
			}
		}
		if(t->data>r->data)// p became NULL and r is a tailing pointer of that p;
		{
			r->right=t;
		}
		else
		{
			r->left=t;
		}
	}
}
//...................................................................................................................
struct node*search( )
{
	int key;
	struct node*p;
	printf("Enter the element to search:\n");
	scanf("%d",&key);
	p=root;
	while(p!=NULL)
	{
		if(key==p->data)
		{
			return p;
		}
		else if(key<p->data)
		{
			p=p->left;
		}
		else
		{
			p=p->right;
		}	
	}
	return NULL;
}
//...............................................................................................................................................
struct node*Rsearch(struct node*p,int key)
{
	if(p==NULL)
	{
		return NULL;
	}
	if(p->data==key)
	{
		return p;
	}
	else if(key<p->data)
	{
		return Rsearch(p->left,key);
	}
	else
	{
		return Rsearch(p->right,key);
	}
}
//..........................................................................................................................
void preorder(struct node*p)
{
	if(p==NULL)
	{
		return;
	}
	printf("%d ",p->data);
	preorder(p->left);
	preorder(p->right);
}
//..........................................................................................................................
void inorder(struct node*p)
{
	if(p==NULL)
	{
		return;
	}
	inorder(p->left);
	printf("%d ",p->data);
	inorder(p->right);
}
//..............................................................................................................................
void postorder(struct node*p)
{
	if(p==NULL)
	{
		return;
	}
	postorder(p->left);
	postorder(p->right);
	printf("%d ",p->data);
}//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main( )
{
	struct  node*q=NULL;
	printf("<<<<<<<<Enter the Root node perfectly>>>>>>>>>\n");
	int t;
	printf("Enter the no of nodes:\n");
	scanf("%d",&t);
	while(t--)
	{
		insert();
	}
	q=search( );
	//q=Rsearch(root,15);
	if(q!=NULL)
		printf("Element  %d found:",q->data);
	else
		printf("Element not found:");
	printf("\n");
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
