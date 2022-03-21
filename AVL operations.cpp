#include<stdio.h>
#include<stdlib.h>
//...............................................................................................
struct node
{
    struct node*left;
    int data;
    int height;
    struct node*right;
}*root=NULL;
//..................................................................................................
int get_height(struct node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    return p->height;
}
//..............................................................................................
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else 
    {
        return b;
    }
}
//..............................................................................................
int getbalance(struct node*p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return get_height(p->left)-get_height(p->right);
    }
}
////..........................................................................................
struct node*min(struct node*p)
{
    struct node*temp=p;
    if(temp==NULL)
    {
        return NULL;
    }
    while(temp and temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
    
}
//...............................................................................
struct node*left_rotation(struct node*p)
{
    struct node *pr=p->right;
    struct node*prl=pr->left;//*prl=p->right->left
    pr->left=p;
    p->right=prl;
    p->height=max(get_height(p->left),get_height(p->right))+1;
    pr->height=max(get_height(pr->left),get_height(pr->right))+1;
    return pr;
}
//...................................................................................
struct node*right_rotation(struct node*p)
{
    struct node*pl=p->left;
    struct node*plr=pl->right;
    pl->right=p;
    p->left=plr;
    p->height=max(get_height(p->left),get_height(p->right))+1;
    pl->height=max(get_height(p->left),get_height(p->right))+1;
    return pl;
}
//.............................................................................
struct node*search(struct node*p,int val)
{
    if(p==NULL)
    {
        return NULL;
    }
    if(p->data==val)
    {
    	return p;
	}
   	else if(val<p->data)
	{
        search(p->left,val);
   	}
  	else
   	{
        search(p->right,val);
   	}
}
//.............................................................................
struct node*insert(struct node*p,int val)
{
    if(p==NULL)
    {
        struct node*t;
        t=(struct node*)malloc(sizeof(struct node));
        t->data=val;
        t->height=1;
        t->left=t->right=NULL;
        return t;
    }
    if(val <p->data)
    {
        p->left=insert(p->left,val);
    }
    else if(val >p->data)
    {
        p->right=insert(p->right,val);
    }
    else 
		return p;
    //  update the balance factor the each node and balance the tree
    p->height=max(get_height(p->left),get_height(p->right))+1;
    int balance=getbalance(p);
    //rotations while inserting the node ...........
    if(balance>1 && val <p->left->data)//RR 
    {
        return right_rotation(p);
    }
    if(balance<-1 && val >p->right->data)//LL
    {
        return left_rotation(p);
    }
    if(balance >1 && val>p->left->data)//LR
    {
        p->left=left_rotation(p->left);
        return right_rotation(p);
    }
    if(balance <-1 && val <p->right->data)//Rl
    {
        p->right=right_rotation(p->right);
        return left_rotation(p);
    }
    return p;
}
//.....................................................................................................
struct node*delete_node(struct node*p,int val)
{
	struct node*temp;
    if(p==NULL)
        return p;
    else if(val < p->data)
        p->left=delete_node(p->left,val);//smile please...........
    else if(val > p->data)
        p->right=delete_node(p->right,val);
    else
    {
    	//deleting the leaf node
		if(p->right==NULL && p->left==NULL){
			p=NULL;
			free(p);
		}
		//node having one child
		else if(p->left==NULL){
			temp=p;
			p=p->right;
			free(temp);
		}
		else if(p->right==NULL){
			temp=p;
			p=p->left;
			free(temp);
		}
		//node having two children
		else{
			temp=min(p->right);
			p->data=temp->data;
			p->right=delete_node(p->right,temp->data);
		}
    }
// rotating after deleting 
    if(p==NULL)
    {
        return p;//value not find;
    }
    //update the height and balance of the treee 
    p->height=max(get_height(p->left),get_height(p->right))+1;
    int balance=getbalance(p);
    //ROTATIONS.........................................
    
    if(balance>1 && getbalance(p->left)>=0)
    {
        return right_rotation(p);          //R1 R0 rotations means deleting the node right side and having the left node balance is either 0 or 1
    }
    if(balance>1 && getbalance(p->left)<0)
    {
        p->left=left_rotation(p->left);//R-1 means deleting the node right side and having the balance of left node -1
        return right_rotation(p);
    }
    if(balance<-1 && getbalance(p->right)<=0) //L1  and L0 having right node balance is 0 or greater than 1
    {
        return left_rotation(p);
    }
    if(balance <-1 && getbalance(p->right)>0)
    {
        p->right=right_rotation(p->right);// L-1 deleting the node left side and having right node balance 0
        return left_rotation(p);
    }
    return p;
}
//.................................................................................
void inorder(struct node*p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
//..................................................................................
void preorder(struct node*p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
//...............................................................................................
void postorder(struct node*p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}
//...........................................................................................
int main( )
{
    int key,ch;
    printf("\n********************AVL TREE OPERATIONS*************************\n");
    while(1)
    {
        printf("\n1.Insert()\n2.search()\n3.Delete()\n4.preorder\n5.inorder\n6.postorder\n7.Exit\n\n");
        printf("Enter the option:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the key to be inserted:");
                scanf("%d",&key);
                root=insert(root,key);
                break;
            case 2:
            	struct node*temp;
                printf("\nEnter the key to be searched:");
                scanf("%d",&key);
                temp=search(root,key);
                if(temp)
                {
                	printf("Element %d is found",temp->data);
				}
				else
				{
					printf("Element not found:");
				}
                break;
            case 3:
                printf("\nEnter the key to be deleted:");
                int key;
                scanf("%d",&key);
                root=delete_node(root,key);
                break;
            case 4:
                printf("\nPreorder Elements: ");
                preorder(root);
                printf("\n");
                break; 
            case 5:
                printf("\nInorder Elements: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("\nPostorder Elements: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(1);
                break;
            default:
                printf("\nEnter the valid option:\n");
        }
    }
}
//.....................................................................................................
