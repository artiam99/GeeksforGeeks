#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	
	node* next;
};

node* insertbegin(int x , node* head)
{
	node* temp = new node();
	temp->data = x;
	
	if(head == NULL)
	{
		head = temp;
		
		temp->next = head;
		
		return head;
	}
	
	node* temp1 = head;
	
	do
	{
		temp1 = temp1->next;
	}while(temp1->next != head);
	
	temp1->next = temp;
	
	temp->next = head;
	
	head = temp;
	
	return head;
}

node* insertend(int x , node* head)
{
	node* temp = new node();

	temp->data = x;

	if(head == NULL)
	{
		head = temp;
		
		temp->next = head;
		
		return head;
	}
	
	node* temp1 = head;
	
	do
	{
		temp1 = temp1->next;
		
	}while(temp1->next != head);
	
	temp1->next = temp;
	
	temp->next = head;
	
	return head;
}

node* insertafter(int x , int y , node* head)
{
	node* temp = new node();
	
	temp->data = x;
	
	node* temp1 = head;
	
	if(head->data == y)
	{
		temp->next = head->next;
		
		head->next = temp;
		
		return head;
	}
	
	do
	{
		temp1=temp1->next;
		
	}while(temp1!=head && temp1->data != y);
	
	temp->next = temp1->next;
	
	temp1->next = temp;
	
	return head;
}

node* findmid(node* head)
{
	node* slow = head;
	
	node* fast = head->next;
	
	while(fast != head)
	{
		fast = fast->next;
	
		if(fast != head)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	return slow;
}

node* deletion(int x , node* head)
{
	if(head->next == head)
	{
		delete head;
		
		return NULL;
	}
	
	node* temp=head;
	
	while(temp->next != head)
	temp = temp->next;
	 
	node* prev = temp , *curr = head;
	
	int p = 0;
	
	do
	{
		if(curr->data == x)
		{
			p = 1;
			
			break;
		}
		
		prev = curr;
		
		curr = curr->next;
		
		if(curr->data == x)
		p = 1;
		
	}while(curr->data != x && curr != head);
	
	if(p == 0)
	return head;
	
	if(curr == head)
	head = curr->next;
	
	prev->next = curr->next;
	
	delete curr;
	
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
}

int main() 
{
	node* head = NULL;
	
	head = insertbegin(2 , head);
	head = insertbegin(1 , head);
	head = insertend(3 , head);
	head = insertend(4 , head);
	head = insertafter(5 , 4 , head);
	
	print(head);
	
	cout << findmid(head)->data << endl;
	
	head = insertend(6 , head);
	
	print(head);
	
	cout << findmid(head)->data << endl;
	
	head = deletion(1 , head);
	
	print(head);
	
	head = deletion(6 , head);
	
	print(head);
	
	head = deletion(3 , head);
	
	print(head);
	
	head = deletion(6 , head);
	
	print(head);
	
	return 0; 
}

