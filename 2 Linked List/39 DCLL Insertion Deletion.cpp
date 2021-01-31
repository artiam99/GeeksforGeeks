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
	
	if(head == NULL)
	{
		head = temp;
		
		temp->next = temp;
		
		temp->prev = temp;
		
		return head;
	}
	
	temp->prev = head->prev;
	
	head->prev->next = temp;
	
	temp->next = head;
	
	head->prev = temp;
	
	head = temp;
	
	return head;
}

node* insertend(int x , node* head)
{
	node* temp = getnode(x);
	
	if(head == NULL)
	{
		head = temp;
		
		temp->next = temp;
		
		temp->prev = temp;
		
		return head;
	}
	
	temp->prev = head->prev;
	
	head->prev->next = temp;
	
	temp->next = head;
	
	head->prev = temp;
	
	return head;
}

node* insertafter(int x , int y , node* head)
{
	node* temp = getnode(x);
	
	node* temp1 = head;
	
	while(temp1->next != head && temp1->data != y)
	temp1 = temp1->next;
	
	if(temp1->data != y)
	{
		delete temp;
		
		return head;
	}
	
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
	
	while(temp1->next != head && temp1->data != y)
	temp1 = temp1->next;
	
	if(temp1->data != y)
	{
		delete temp;
	
		return head;
	}
	
	temp1->prev->next = temp;
	
	temp->prev = temp1->prev;
	
	temp->next = temp1;
	
	temp1->prev = temp;
	
	if(temp1 == head)
	head = temp;
	
	return head;
}

node* deletion(int x , node* head)
{
	if(head == NULL)
	return head;
	
	node* temp = head;
	
	while(temp->next != head && temp->data != x)
	temp = temp->next;
	
	if(temp->data != x)
	return head;
	
	if(temp == head && temp->next == head)
	{
		delete head;
		
		head = NULL;
		
		return head;
	}
	
	temp->prev->next = temp->next;
	
	temp->next->prev = temp->prev;
	
	if(head == temp)
	head = temp->next;
	
	delete temp;
	
	return head;
}

void print(node* head)
{
	if(head == NULL)
	return;

	node* temp = head;
	
	do
	{
		cout << temp->data << " ";
		
		temp = temp->next;
	
	}while(temp != head);
	
	cout << endl;

	temp = head->prev;

	do
	{
		cout << temp->data << " ";
		
		temp = temp->prev;
		
	}while(temp != head->prev);
	
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

