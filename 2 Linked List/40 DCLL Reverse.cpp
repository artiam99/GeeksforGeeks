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

node* reverseit(node* head)
{
	node* prev = head->prev , *cur = head , *next;

	do
	{
		next = cur->next;
		
		cur->next = prev;
		
		cur->prev = next;
		
		prev = cur;
		
		cur = next;
		
	}while(cur != head);
	
	return prev;
}

node* reverserec(node* p , node* head)
{
	if(p->next == head)
	{
		head = p;
		
		swap(p->next , p->prev);
		
		return head;
	}
	
	head = reverserec(p->next , head);
	
	swap(p->next , p->prev);
	
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

	head = insert(1 , head);
	head = insert(2 , head);
	head = insert(3 , head);
	head = insert(4 , head);
	
	print(head);
	
	head = reverseit(head);
	
	print(head);
	
	head = reverserec(head , head);
	
	print(head);
	
	return 0;
}

