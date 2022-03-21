#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node  *right;
}*root=NULL;
//.............................................................................................................
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
//..........................................................................................................
struct node*search()
{
	int key;
	struct node*t=root;
	printf("\nEnter the key to search:\n");
	scanf("%d",&key);
	while(t!=NULL)
	{
		if(t->data==key)
		{
			return t;
		}
		else if(key<t->data)
		{
			t=t->left;
		}
		else
		{
			t=t->right;
		}
	}
	return NULL;
}
//.....................................................................................................................
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
//....................................................................................................................
struct node*Rsearch(struct node*t,int key)
{
	if(t==NULL)
	{
		return NULL;
	}
	if(t->data=key)
	{
		return t;
	}
	else if(key<t->data)
	{
		return Rsearch(t->left,key);
	}
	else
	{
		return Rsearch(t->right,key);
	}
}
//....................................................................................................
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
//..............................................................................................
int main( )
{
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<BINARY SEARCH TREE OPERATIONS:>>>>>>>>>>>>>>>>>\n\n");
 	while(1)
 	{
 		int key,ch;
 		struct node *p;
 		printf("1.insert()\n2.Deletion()\n3.search()\n4.preorder\n5.inorder\n6.Postorder\n7.Exit()\n\n");
 		printf("Enter the choice:\n");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:
 				printf("Enter the element you want to insert:\n");
				scanf("%d",&key);
				root=insert(root,key);
			 	break;
 			case 2:
 				printf("\nEnter the element you want to delete:\n");
				scanf("%d",&key);
				root=delete_node(root,key);
			 	break;
 			case 3:p=search();
				if(p)
				{
					printf("Element found %d",p->data);
				}
				else
				{
					printf("\nElement not found:");
				}
			 	break;
			case 4:
				printf("\nPREORDER TRAVERSAL:\n");
				preorder(root);
				printf("\n");
				break;
			case 5:
				printf("\nINORDER TRAVERSAL:\n");
				inorder(root);
				printf("\n");
				break;
			case 6:
				printf("\nPOSTORDER TRAVERSAL:\n");
				postorder(root);
				printf("\n");
				break;
 			case 7:exit(1);break;
 			default:
 				printf("Please Enter the valid option again:\n");	
		}
	 }
}
