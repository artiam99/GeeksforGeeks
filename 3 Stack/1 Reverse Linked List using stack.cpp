#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	
	node* next;
};

node* insert(node** head , int x)
{
	node* temp = new node();
	
	temp->data = x;
	
	temp->next = NULL;
	
	node** cur = head;
	
	while(*cur)
	cur = &((*cur)->next);
	
	*cur = temp;
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

void reverse(node** head)
{
	stack<node*> s;
	
	node* temp = *head;
	
	while(temp)
	{
		s.push(temp);
	
		temp = temp->next;
	}
	
	*head = s.top();
	
	s.pop();
	
	temp = *head;
	
	while(!s.empty())
	{
		temp->next = s.top();
		
		s.pop();
		
		temp = temp->next;
	}
	
	temp->next = NULL;
}

int main()
{
	node* head = NULL;

	insert(&head , 1);
	insert(&head , 2);
	insert(&head , 3);
	insert(&head , 4);
	insert(&head , 5);
	
	print(head);
	
	reverse(&head);
	
	print(head);
	
	return 0; 
} 

