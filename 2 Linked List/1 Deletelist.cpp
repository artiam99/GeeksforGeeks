#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* insert(int x , int n , node* head)
{
	node* temp = new node;
	
	temp->data = x;
	
	temp->next = NULL;
	
	if(n == 0)
	{
		temp->next = head;
		
		head = temp;
		
		return head;
	}
	
	node* temp1 = head;
	
	for(int i = 0 ; i < n-1 ; i++)
	temp1 = temp1->next;
	
	temp->next = temp1->next;
	
	temp1->next = temp;
	
	return head;
}

void print(node* head)
{
	node* temp = head;

	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	
	cout << endl;
}

void deletelinkedlist(node *head)
{
	node* temp;

	while(head)
	{
		temp = head;
		
		head = temp->next;
		
		cout << temp->data << " is deleted" << endl;
		
		delete temp;
	}
}

int main() 
{
	node* head = NULL;
	
	head = insert(2 , 0 , head);
	head = insert(3 , 0 , head);
	head = insert(4 , 2 , head);
	head = insert(5 , 2 , head);
	
	print(head);
	
	deletelinkedlist(head);
	
	return 0; 
} 

