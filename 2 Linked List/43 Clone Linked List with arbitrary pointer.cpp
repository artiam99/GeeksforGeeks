#include<iostream>
using namespace std;

struct node
{
	int data;

	node *next,*abr;
};

node* insert(node* head , int x)
{
	node* temp = new node();
	
	temp->data = x;
	
	temp->next = NULL;
	
	if(head == NULL)
	{
		head = temp;
		
		return head;
	}
	
	node* temp1 = head;
	
	while(temp1->next)
	temp1 = temp1->next;
	
	temp1->next = temp;
	
	return head;
}

node* clone(node* head)
{
	if(head == NULL)
	return NULL;

	node* cur = head , *temp;
	
	while(cur)
	{
		temp = cur->next;
		
		cur->next = new node();
		
		cur->next->data = cur->data;
		
		cur->next->next = temp;
		
		cur = temp;
	}
	
	cur = head;

	temp = head->next;
	
	while(cur)
	{
		temp->abr = (cur->abr ? cur->abr->next : cur->abr);

		temp = (temp->next ? temp->next->next : temp->next);

		cur = cur->next->next;
	}
	
	cur = head;
	
	temp = head->next;
	
	node* head2 = temp;
	
	while(cur)
	{
		cur->next = cur->next->next;
	
		temp->next = (temp->next ? temp->next->next : temp->next);
	
		cur = cur->next;
	
		temp = temp->next;
	}
	
	return head2;
}

void print(node* head)
{
	while(head)
	{
		cout << head->data << " " << head->abr->data << endl;

		head = head->next;
	}
	
	cout << endl;
}

int main()
{
	node* head = NULL;

	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 3);
	head = insert(head , 4);
	
	head->abr = head->next->next;
	head->next->abr = head->next->next->next;
	head->next->next->abr = head->next;
	head->next->next->next->abr = head;
	
	print(head);
	
	node* head2 = clone(head);
	
	print(head);
	
	print(head2);
	
	return 0;
}

