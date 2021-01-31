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

void insert(int x , node** head , node** tail)
{
	node* temp = getnode(x);
	
	if(*head == NULL)
	{
		*head = temp;
		
		*tail = temp;
		
		return;
	}
	
	node* temp1 = *head;
	
	node* prev = NULL;
	
	while(temp1 != NULL && temp1->data < x)
	{
		prev = temp1;
		
		temp1 = temp1->next;
	}
	
	if(prev != NULL)
	prev->next = temp;
	
	else
	*head = temp;
	
	temp->prev = prev;
	
	if(temp1 != NULL)
	temp1->prev = temp;
	
	else
	*tail = temp;
	
	temp->next = temp1;
}

void print(node* head , node* tail)
{
	node* temp = head;
	
	while(temp != NULL)
	{
		cout << temp->data << " ";
		
		temp = temp->next;
	}
	
	cout << endl;
	
	temp = tail;
	
	while(temp != NULL)
	{
		cout << temp->data << " ";

		temp = temp->prev;
	}
	
	cout << endl << endl;
}

int main() 
{
	node* head = NULL , *tail = NULL;
	
	insert(3 , &head , &tail);
	
	print(head , tail);
	
	insert(6 , &head , &tail);
	
	print(head , tail);
	
	insert(2 , &head , &tail);
	
	print(head , tail);
	
	insert(12 , &head , &tail);
	
	print(head , tail);
	
	insert(56 , &head , &tail);
	
	print(head , tail);
	
	insert(8 , &head , &tail);
	
	print(head , tail);
	
	return 0;
}

