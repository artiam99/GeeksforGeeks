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
	node* temp = new node();

	temp->data = x;

	temp->next = NULL;

	temp->prev = NULL;

	return temp;
}

node* insert(int x , node* head)
{
	node* temp = getnode(x);

	if(head == NULL)
	{
		head = temp;

		return head;
	}

	node* temp1 = head;
	
	while(temp1->next != NULL)
	temp1 = temp1->next;
	
	temp->prev = temp1;
	
	temp1->next = temp;
	
	return head;
}

node* reverse(node* head)
{
	node* prev = NULL;

	while(head)
	{
		swap(head->next , head->prev);
		
		prev = head;
		
		head = head->prev;
	}
	
	return prev;
}

node* merge(node* head1 , node* head2)
{
	if(!head1)
	return head2;
	
	if(!head2)
	return head1;
	
	node* head;
	
	if(head1->data < head2->data)
	{
		head = head1;
		
		head->next = merge(head1->next , head2);
		
		if(head->next)
		head->next->prev = head;
	}
	
	else
	{
		head = head2;
	
		head->next = merge(head1 , head2->next);
		
		if(head->next)
		head->next->prev = head;
	}
	
	return head;
}

node* sortlist(node* head)
{
	node* temp = head;

	while(temp && temp->next && temp->next->data > temp->data)
	temp = temp->next;

	node* temp1 = temp->next;
	
	temp->next = NULL;
	
	if(temp1)
	temp1->prev = NULL;
	
	temp1 = reverse(temp1);
	
	return merge(head , temp1);
}

void print(node* head)
{
	node* temp = head;
	
	node* temp1;
	
	while(temp != NULL)
	{
		temp1 = temp;
		
		cout << temp->data << " ";
		
		temp = temp->next;
	}
	
	cout << endl;
	
	while(temp1 != NULL)
	{
		cout << temp1->data << " ";
		
		temp1 = temp1->prev;
	}
	
	cout << endl << endl;
}

int main() 
{
	node* head = NULL;

	head = insert(2 , head);
	head = insert(5 , head);
	head = insert(7 , head);
	head = insert(12 , head);
	head = insert(10 , head);
	head = insert(6 , head);
	head = insert(4 , head);
	head = insert(1 , head);		
	
	print(head);
	
	head = sortlist(head);

	print(head);

	head = NULL;

	head = insert(20 , head);
	head = insert(27 , head);
	head = insert(14 , head);
	head = insert(8 , head);
	head = insert(3 , head);
	
	print(head);
	
	head = sortlist(head);
	print(head);
	
	head = NULL;
	
	head = insert(1 , head);
	head = insert(2 , head);
	head = insert(3 , head);
	head = insert(4 , head);
	head = insert(5 , head);

	print(head);
	
	head = sortlist(head);

	print(head);

	return 0;
}

