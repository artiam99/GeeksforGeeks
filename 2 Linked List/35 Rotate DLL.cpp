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

node* rotate(int n , node* head)
{
	node* temp = head;
	
	int c = 1;
	
	while(temp->next)
	{
		c++;
	  
	    temp = temp->next;
    }
    
    n %= c;
    
	node* temp1 = head;
	
	for(int i = 0 ; i < n ; i++)
	temp1 = temp1->next;
	
	if(temp1 == head)
	return head;
	
	node* prev = temp1->prev;
	
	prev->next = NULL;
	
	temp1->prev = NULL;
	
	temp->next = head;
	
	head->prev = temp;
	
	return temp1;
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
	head = insert(5 , head);
	
	print(head);
	
	head = rotate(4 , head);
	
	print(head);
	
	return 0;
}

