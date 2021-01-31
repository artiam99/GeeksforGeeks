#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;

	node* next;
};

node* insert(node* head , int x)
{
	node* temp = new node();

	temp->data = x;

	temp->next = head;

	head = temp;

	return head;
}

bool find(node* head1 , node* head2)
{
	node* temp1 = head1;

	node* temp2 = head2;

	while(temp1)
	{
		node* next = temp1->next;
		
		while(temp2 && temp1 && temp1->data == temp2->data)
		{
			temp1 = temp1->next;
			
			temp2 = temp2->next;
		}
		
		if(!temp2)
		return true;

		temp1 = next;

		temp2 = head2;
	}

	return false;
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

int main()
{
	node* head = NULL;
	node* head1 = NULL;

	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 3);
	head = insert(head , 4);
	head = insert(head , 5);
	
	print(head);
	
	head1 = insert(head1 , 3);
	head1 = insert(head1 , 1);
	head1 = insert(head1 , 2);
	
	print(head1);
	
	if(find(head , head1))
	cout << "List found" << endl;
	
	else
	cout << "Not found" << endl;
	
	return 0;
}

