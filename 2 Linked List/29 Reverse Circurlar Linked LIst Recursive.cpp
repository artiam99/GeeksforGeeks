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

node* reverse(node* p , node* head)
{
	if(p->next == head)
	return p;
	
	head = reverse(p->next , head);
	
	p->next->next = p;
	
	p->next = head;
	
	return head;
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

	head = insert(1 , head);
	head = insert(2 , head);
	head = insert(3 , head);
	head = insert(4 , head);
	head = insert(5 , head);
	
	print(head);
	
	head = reverse(head , head);
	
	print(head);
	
	return 0;
}
