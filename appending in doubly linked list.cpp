#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node *prev;
	int data;
	struct node *next;
}*head=NULL,*tail=NULL;
void append()
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	if(t==NULL)
	{
		printf("memory allocation failed");
	}	
	printf("Enter the elemet:\n");
	scanf("%d",&t->data);
	t->next=NULL;
	t->prev=NULL;
	if(head==NULL)
	{
		head=tail=t;
	}
	else
	{
		tail->next=t;
		t->prev=tail;
		tail=t;
	}
}
void display()
{
	struct node*temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
}
int main( )
{
	int t;
	printf("enter the no of elements:\n");
	scanf("%d",&t);
	while(t--)
	{
		append();
	}
	display();
	return 0;
}