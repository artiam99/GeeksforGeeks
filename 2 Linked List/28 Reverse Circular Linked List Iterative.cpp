#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;

	node* next;	
};

node* insert(int x , node* head)
{
	node* temp = new node();
	
	temp->data = x;
	
	if(head == NULL)
	{
		temp->next = temp;
		
		head = temp;
		
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

node* reverse(node* head)
{
	node* prev , *cur = head , *next;
	
	node* temp = head;
	
	do
	{
		temp = temp->next;
	
	}while(temp->next != head);
	
	prev = temp;
	
	do
	{
		next = cur->next;
		
		cur->next = prev;
		
		prev = cur;
		
		cur = next;

	}while(cur != head);
	
	return prev;
}

void print(node* head)
{
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
	
	head = insert(6 , head);
	head = insert(7 , head);

	print(head);
	
	head = reverse(head);
	
	print(head);
	
	return 0;
}
