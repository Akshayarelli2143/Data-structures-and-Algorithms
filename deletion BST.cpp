#include<stdio.h>
#include<stdlib.h>
struct node
{
 	struct node*left;
 	int data;
 	struct node*right;
}*root=NULL;
//........................................................................................................................
struct node*getmin(struct node*temp)
{
	while(temp and temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}
//...................................................................................................................
struct node*getmax(struct node*temp)
{
	while(temp and temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp;
}
//..................................................................................................................
void insert( )
{
	struct node*t,*r,*p;
	t=(struct node*)malloc(sizeof(struct node));
	if(root==NULL)
	{
		printf("\nEnter the Root data:\n");
		scanf("%d",&t->data);
		t->left=t->right=NULL;
		root=t;
	}
	else
	{
		printf("Enter the data:\n");
		scanf("%d",&t->data);
		t->left=t->right=NULL;
		p=root;
		while(p!=NULL)
		{
			r=p;
			if(t->data==p->data)
			{
				return;
			}
			else if(t->data>p->data)
			{
				p=p->right;
			}
			else
			{
				p=p->left;
			}
		}
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
//............................................................................................................................
struct node*delete_node(struct node*p,int val)
{
	if(p==NULL)//struct node*p=root;  p changes every recursive call
	{
		return p;
	}
	if(val<p->data)
	{
		p->left=delete_node(p->left,val);
	}
	else if(val>p->data)
	{
		p->right=delete_node(p->right,val);
	}
	else
	{
		//node having leaf node
		if(p->left==NULL && p->right==NULL)
		{
			return NULL;
			free(p);
		}
		//node having only one child
		else if(p->right==NULL)
		{
			struct node*temp=p->left;
			free(p);
			return temp;
		}
		else if(p->left==NULL)
		{
			struct node*temp=p->right;
			free(p);
			return temp;
		}
		//node having two child
		struct node*temp=getmin(p->right);//fing the inorder succesor
		p->data=temp->data;//copying the data 
		p->right=delete_node(p->right,temp->data);// deleting the inorder succesor	
	}
	return p;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int height(struct node*p)
{
	int x=0,y=0;
	if(p==NULL)
	{
		return 0;
	}
	x=height(p->left);
	y=height(p->right);
	if(x>y)
	{
		return x+1;
	}
	else
	{
		return y+1;
	}
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void preorder(struct node *p)
{
	if(p==NULL)
	{
		return;
	}
	printf("%d ",p->data);
	preorder(p->left);
	preorder(p->right);
}
//.............................................................................................................................
void inorder(struct node *p)
{
	if(p==NULL)
	{
		return;
	}
	inorder(p->left);
	printf("%d ",p->data);
	inorder(p->right);
}
//.........................................................................................................................
void postorder(struct node *p)
{
	if(p==NULL)
	{
		return;
	}
	postorder(p->left);
	postorder(p->right);
	printf("%d ",p->data);
}
//..............................................................................................................................
int main( )
{
	int t,val;
	printf("Enter the no of nodes:\n");
	scanf("%d",&t);
	while(t--)
	{
		insert();
	}
	printf("\nPREORDER\n");
	preorder(root);
	
	printf("\nmin value =%d",getmin(root)->data);
	printf("\nmax value =%d",getmax(root)->data);
	
	printf("\nEnter the element you want to delete:\n");
	scanf("%d",&val);
	root=delete_node(root,val);
	printf("\nHeight of the tree:\n");
	printf("%d ",height(root));
	printf("\nPREORDER\n");
	preorder(root);
	printf("\nINORDER\n");
	if(root==NULL)
	{
		printf("TREE is empty:\n");
	}
	else
	{
		inorder(root);							
	}
	printf("\nPOSTORDER\n");
	postorder(root);
}
//....................................................................................................................
