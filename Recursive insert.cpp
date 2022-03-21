#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*left;
	int data;
	struct node*right;
};
//..........................................................................................................................
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
//.........................................................................................................................
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
//...........................................................................................................................
int main( )
{
	struct node*root=NULL;
	root=insert(root,30);
	insert(root,20);
	insert(root,10);
	insert(root,25);
	insert(root,40);
	insert(root,45);
	
	inorder(root);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
