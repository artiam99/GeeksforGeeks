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

node* insertbegin(int x , node* head)
{
	node* temp = getnode(x);

	if(head!=NULL)
	head->prev = temp;

	temp->next = head;
	
	head = temp;
	
	return head;
}

node* insertend(int x , node* head)
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

node* insertafter(int x , int y , node* head)
{
	node* temp = getnode(x);
	
	node* temp1 = head;
	
	while(temp1->next != NULL && temp1->data != y)
	temp1 = temp1->next;
	
	if(temp1->data != y)
	{
		delete temp;
		
		return head;
	}
	
	if(temp1->next != NULL)
	temp1->next->prev = temp;
	
	temp->next = temp1->next;
	
	temp->prev = temp1;
	
	temp1->next = temp;
	
	return head;
}

node* insertbefore(int x , int y , node* head)
{
	node* temp = getnode(x);
	
	node* temp1 = head;
	
	node* prev = NULL;
	
	while(temp1->next != NULL && temp1->data != y)
	{
		prev = temp1;
	
		temp1 = temp1->next;
	}
	
	if(temp1->data != y)
	{
		delete temp;
		
		return head;
	}
	
	if(prev != NULL)
	prev->next = temp;
	
	else
	head = temp;
	
	temp->prev = prev;
	
	temp->next = temp1;
	
	temp1->prev = temp;
	
	return head;
}

node* deletion(int x,node* head)
{
	node* temp = head;
	
	node* prev = NULL;
	
	while(temp->next != NULL && temp->data != x)
	{
		prev = temp;
		
		temp = temp->next;
	}
	
	if(prev != NULL)
	prev->next = temp->next;
	
	else
	head = temp->next;
	
	if(temp->next != NULL)
	temp->next->prev = prev;
	
	delete temp;
	
	return head;
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

	head = insertbegin(2 , head);

	print(head);

	head = insertbegin(1 , head);

	print(head);

	head = insertafter(4 , 2 , head);

	print(head);

	head = insertbefore(3 , 4 , head);

	print(head);

	head = deletion(3 , head);

	print(head);

	head = deletion(4 , head);

	print(head);

	head = deletion(1 , head);

	print(head);

	return 0;
}
