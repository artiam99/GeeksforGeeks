#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* prev;
	node* next;	
};
node* getnode(int x)
{
	node* temp=new node();
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
node* insert(int x,node* head)
{
	node* temp=getnode(x);
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	node* temp1=head;
	while(temp1->next!=NULL)
	temp1=temp1->next;
	temp->prev=temp1;
	temp1->next=temp;
	return head;
}
node* merge(node* a,node* b)
{
	node* head=NULL;
	node** ref=&head;
	node* prev=NULL;
	
	while(a&&b)
	{
		if(a->data<b->data)
		{
			a->prev=prev;
			*ref=a;
			prev=a;
			a=a->next;
		}
		else
		{
			b->prev=prev;
			*ref=b;
			prev=b;
			b=b->next;
		}
		ref=&((*ref)->next);
	}
	if(a)
	{
		a->prev=prev;
		*ref=a;
	}
	else
	{
		b->prev=prev;
		*ref=b;
	}
	return head;
}
void print(node* head)
{
	node* temp=head;
	node* temp1;
	while(temp!=NULL)
	{
		temp1=temp;
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	while(temp1!=NULL)
	{
		cout<<temp1->data<<" ";
		temp1=temp1->prev;
	}
	cout<<endl<<endl;
}
int main() 
{
	node* head1=NULL;
	head1=insert(1,head1);
	head1=insert(4,head1);
	head1=insert(6,head1);
	head1=insert(8,head1);
	print(head1);
	
	node* head2=NULL;
	head2=insert(2,head2);
	head2=insert(3,head2);
	head2=insert(7,head2);
	head2=insert(9,head2);
	print(head2);
	
	node* head=merge(head1,head2);
	
	print(head);
	return 0;
} 
