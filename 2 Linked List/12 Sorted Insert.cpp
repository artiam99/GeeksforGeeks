#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	
	node* next;
};

node* sortedinsert(int x , node* head)
{
	node* temp = new node;
	
	temp->data = x;
	
	node** h = &head;
	
	while(*h && (*h)->data < x)
	h = &((*h)->next);
	
	temp->next = *h;
	
	*h = temp;

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

int main() 
{
	srand(time(NULL));

	node* head = NULL;

	head = sortedinsert(5 , head);
	head = sortedinsert(3 , head);
	head = sortedinsert(4 , head);
	head = sortedinsert(2 , head);
	head = sortedinsert(4 , head);

	print(head);

	return 0; 
}
