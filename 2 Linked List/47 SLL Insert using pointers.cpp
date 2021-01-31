#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;

	node* next;
};

node* sortedinsert(node* head , int x)
{
	node* temp = new node();
	
	temp->data = x;
	
	node** cur = &head;
	
	while(*cur && (*cur)->data < x)
	cur = &((*cur)->next);
	
	temp->next = *cur;
	
	*cur = temp;
	
	return head;
}

node* insertbegin(node* head , int x)
{
	node* temp = new node();

	temp->data = x;

	temp->next = NULL;

	node** cur = &head;

	temp->next = *cur;
	
	*cur = temp;
	
	return head;
}

node* insertend(node* head , int x)
{
	node* temp = new node();
	
	temp->data = x;
	
	node** cur = &head;
	
	while(*cur)
	cur = &((*cur)->next);
	
	temp->next = *cur;
	
	*cur = temp;
	
	return head;
}

node* insertnth(node* head , int x , int n)
{
	node* temp = new node();
	
	temp->data = x;
	
	node** cur = &head;
	
	for(int i = 1 ; i < n ; i++)
	cur = &((*cur)->next);

	temp->next = *cur;

	*cur = temp;

	return head;
}

void print(node* head)
{
	while(head)
	{
		cout << head->data << " ";

		head = head->next;
	}

	cout << endl;
}

int main()
{
	node* head = NULL;

	head = sortedinsert(head , 4);
	head = sortedinsert(head , 2);
	head = insertbegin(head , 1);
	head = insertend(head , 5);
	head = insertnth(head , 3 , 3);

	print(head);

	return 0;
}

