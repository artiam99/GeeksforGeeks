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

int count(node* head)
{
	int c = 0;

	while(head)
	{
		head = head->next;
	
		c++;
	}
	
	return c;
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

void printreverse(node* head , int n)
{
	int j = 0;
	
	while(head)
	{
		for(int i = 0 ; i < 2 * (n-j-1) ; i++)
		cout << " ";
	
		cout << head->data << "\r";
		
		head = head->next;
		
		j++;
	}
}

int main()
{
	node* head = NULL;
	
	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 3);
	head = insert(head , 4);
	head = insert(head , 5);

	print(head);

	int n = count(head);

	printreverse(head , n);

	return 0;
}

