#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*left;
	int data;
	struct node*right;
};
//.............................................................................................................
struct node *create( )
{
	int x;//local variable each time will create a new one with new activation record
	struct node*t;
	t=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&x);
	if(x==-1)
	{
		return NULL;//return 0;
	}
	t->data=x;
	printf("\nEnter the left child of %d\n",x);
	t->left=create();
	printf("\nEnter the right child of %d\n",x);
	t->right=create();
	return t;
}
//...........................................................................................................
void preorder(struct node *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
//........................................................................................................
void inorder(struct node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d ",p->data);
		inorder(p->right);
	}
}
//...........................................................................................................
void postorder(struct node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ",p->data);
	}
}
//......................................................................................................
struct node*search(struct node*p,int val)
{
	if(p->data==val)
	{
		return p;
	}
	{
		search(p->left,val);
		search(p->right,val);
	}
	return 0;
}
//.........................................................................................................
int main( )
{	
	struct node *root,*temp;
	int key;
	printf("Binary Tree implementation:\n");
	root=create( );
	printf("\n\nPreorder:");
	preorder(root);
	printf("\n\nInorder:");
	inorder(root);
	printf("\n\nPostorder:");
	postorder(root);
	printf("\nEnter the element to search:\n");
	scanf("%d",&key);
	temp=search(root,key);
	if(temp)
	{
		printf("element found %d",temp->data);
	}
	else
	{
		printf("element not found");
	}
	
}
//..........................................................................................................
