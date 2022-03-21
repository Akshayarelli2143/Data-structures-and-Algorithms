#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node  *right;
}*root=NULL;
//.....................................................................................................................
void insert()//iterative insert 
{
	int x;
	struct node *t,*r,*p;
	t=(struct node *)malloc(sizeof(struct node));
	if(root==NULL)//
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
		// p became NULL and r is a tailing pointer of that p;
		if(t->data>r->data)
		{
			r->right=t;
		}
		else
		{
			r->left=t;
		}
	}
}
//........................................................................................
struct node*insert(struct node*p,int val)
{
	/* If the tree is empty, return a new node */
	if(p==NULL)
	{
		struct node *t;
		t=(struct node*)malloc(sizeof(struct node));
		t->data=val;
		t->left=t->right=NULL;
		return t;
	}
	/* Otherwise, recur down the tree */
	if(val<p->data)
	{
		p->left=insert(p->left,val);
	}
	else
	{
		p->right=insert(p->right,val);
	}
	/* return the (unchanged) node pointer */
	return p;
}
//.............................................................................................................
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
//............................................................................................................................
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
//...............................................................................................................................................
void postorder(struct node*p)
{
	if(p==NULL)
	{
		return;
	}
	postorder(p->left);
	postorder(p->right);
	printf("%d ",p->data);
}
//.............................................................................................................................
int main( )
{
	printf("<<<<<<<<Enter the Root node perfectly>>>>>>>>>\n");
	int t;
	printf("Enter the no of nodes:\n");
	scanf("%d",&t);
	while(t--)
	{
		insert();
	}
	printf("\n");
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}
//...........................................................................................................................
