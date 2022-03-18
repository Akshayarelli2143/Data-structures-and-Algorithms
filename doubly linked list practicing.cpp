#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
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
	printf("Enter the element:\n");
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
void solve( )
{
	int key,x;
	struct node *p,*q,*temp;
	//temp=(struct node*)malloc(sizeof(struct node));
	p=head;
	q=p->next;
	printf("Enter the key to be deleted:\n");
	scanf("%d",&key);
	while(q!=NULL)
	{
		if(q->data==key)
		{
			p->next=q->next;
			q->next=NULL;
			free(q);
		}
		q=q->next;
		p=p->next;
	}
	temp->data=key;
	temp->next=head;
	head=temp;
}
void reverse()
{
	struct node*temp,*p=head;
	while(p!=NULL)
	{
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		p=p->prev;
		if(p!=NULL && p->next==NULL)
		{
			head=p;
		}
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
	printf("\n");
}
int main( )
{
	int t;
	cout<<"Enter the no of elements:\n";
	cin>>t;
	while(t--)
	{
		append();
	}
	display();
	solve();
	display();
}
