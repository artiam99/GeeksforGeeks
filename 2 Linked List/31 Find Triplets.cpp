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

int findpair(int x , int f , node* head)
{
	node* tail = head;
	
	while(tail->next != NULL)
	tail = tail->next;
	
	while(head->prev != tail && head != tail)
	{
		if(head->data + tail->data == x)
		{
			cout << f << " " << head->data << " " << tail->data << endl;
			
			head = head->next;
			
			tail = tail->prev;
		}
		
		else if(head->data + tail->data < x)
		head = head->next;
		
		else
		tail = tail->prev;
	}
}

void findtriplets(int x , node* head)
{
	if(!(head&&head->next && head->next->next))
	return;
	
	node* temp = head;
	
	while(temp->next->next != NULL)
	{
		findpair(x-temp->data , temp->data , temp->next);
		
		temp = temp->next;
	}
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
	head = insert(6 , head);
	head = insert(7 , head);
	
	print(head);
	
	cout << "Triplets with sum is equal to 9 are : " << endl;

	findtriplets(9 , head);

	return 0;
}

