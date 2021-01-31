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

node* findmid(node* left , node* right)
{
	node* slow = left;
	
	node* fast = left->next;
	
	while(fast != right)
	{
		fast = fast->next;
		
		if(fast != right)
		{
			slow = slow->next;
			
			fast = fast->next;
		}
	}
	
	return slow->next;
}

node* mer(node* head1 , node* head2)
{
	if(head1 == NULL)
	return head2;

	if(head2 == NULL)
	return head1;

	node* head = NULL;
	
	if(head1->data < head2->data)
	{
		head = head1;
	
		head->next = mer(head1->next , head2);
	}
	
	else
	{
		head = head2;
	
		head->next = mer(head1 , head2->next);
	}
	
	return head;
}

node* merge(node* head1 , node* head2)
{
	node* temp1 = head1;
	
	node* temp2 = head2;
	
	do
	{
		temp1 = temp1->next;
	
	}while(temp1->next != head1);
	
	do
	{
		temp2 = temp2->next;
		
	}while(temp2->next != head2);
	
	temp1->next = NULL;
	
	temp2->next = NULL;
	
	node* head = mer(head1 , head2);
	
	node* temp = head;
	
	while(temp->next != NULL)
	temp = temp->next;
	
	temp->next = head;
	
	return head;
}

node* mergesort(node* left , node* right)
{
	if(left == NULL)
	return left;
	
	if(left->next != right)
	{
		node* mid = findmid(left , right);
		
		node* l = mergesort(left , mid);
		node* r = mergesort(mid , right);
		
		return merge(l , r);
    }
    
	left->next = left;
	
	return left;  
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

	head = insert(5 , head);
	head = insert(1 , head);
	head = insert(4 , head);
	head = insert(2 , head);
	head = insert(3 , head);

	print(head);

	head = mergesort(head , head);

	print(head);

	return 0;
}

