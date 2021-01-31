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

void rev(node* head , node* temp)
{
	if(head == temp)
	{
		swap(head->next , head->prev);
		
		return;
	}
	
	rev(head->next , temp);
	
	swap(head->next , head->prev);
}

void group(int n , node* head)
{
	node* temp = head;
	
	for(int i = 0 ; temp->next && i < n-1 ; i++)
	temp = temp->next;
	
	if(temp->next)
	temp->next->prev = head;
	
	if(head->prev)
	head->prev->next = temp;
	
	swap(head->prev , temp->next);
	
	rev(head , temp);
	
	if(head->next)
	group(n , head->next);
}

node* groupreverse(int n , node* head)
{
	node* temp = head;
	
	for(int i = 0 ; temp->next && i < n-1 ; i++)
	temp = temp->next;

	group(n , head);

	return temp;
}

void print(node* head)
{
	node* temp=head;

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
	head = insert(5 , head);
	head = insert(6 , head);
	head = insert(7 , head);
	head = insert(8 , head);
	
	print(head);
	
	head = groupreverse(3 , head);
	
	print(head);
	
	return 0;
}

