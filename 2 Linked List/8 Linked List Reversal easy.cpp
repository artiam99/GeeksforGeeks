#include<iostream>
using namespace std;

class node
{
	public:
	
	int data;
	
	node* next;
};

node* head;

void insert(int x)
{
	node* temp = new node();

	temp->data = x;

	temp->next = NULL;

	if(head == NULL)
	{
		head = temp;
		
		return;
	}
	
	node* temp1 = head;
	
	while(temp1->next != NULL)
	temp1 = temp1->next;
	
	temp1->next = temp;
}

void print()
{
	node* temp = head;
	
	while(temp != NULL)
	{
		cout << temp->data;
		
		temp = temp->next;
	}
}

void reverse(node* cur , node* prev = NULL)
{
	if(!cur->next)
	{
		head = cur;
		
		cur->next = prev;
		
		return;
	}
	
	node* next = cur->next;
	
	cur->next = prev;
	
	reverse(next , cur);
}

int main()
{
	head = NULL;

	cout << "Enter number of elements you want to add : ";
	
	int n , x;
	
	cin >> n;
	
	cout << "Enter element to store at the end: " << endl;
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> x;

		insert(x);
	}
	
	cout << "Linked List :";
	
	print();
	
	cout << "\nReversed Linked List :";
	
	reverse(head);
	
	print();
	
	return 0;
 }
 
