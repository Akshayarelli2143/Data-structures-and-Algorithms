#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
	int data;
	struct node *next;
}*head=NULL,*tail=NULL;
void append()
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	printf("Enter the element:\n");
	scanf("%d",&t->data);
	t->next=NULL;
	if(t==NULL)
		printf("memory allocation failed:\n");
	if(head==NULL)
	{
		head=tail=t;
	}
	else
	{
		tail->next=t;
		tail=t;
	}
}
void display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	   append( );
	}
	display(head);
}
	
