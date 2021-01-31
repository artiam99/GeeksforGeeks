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
	
	node* temp1=head;
	
	while(temp1->next != NULL)
	temp1 = temp1->next;
	
	temp->prev = temp1;
	
	temp1->next = temp;
	
	return head;
}

node* reverse(node* head)
{
	node* prev = NULL , *cur = head , *next;

	while(cur)
	{
		next = cur->next;

		cur->next = prev;

		cur->prev = next;

		prev = cur;

		cur = next;
	}
	
	return prev;
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
	
	head = insert(1 , head);
	head = insert(2 , head);
	head = insert(3 , head);
	head = insert(4 , head);
	
	print(head);
	
	head = reverse(head);
	
	print(head);
	
	return 0;
}
