#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;

	node* next;
};

void insert(node** head , int x)
{
	node* temp = new node();
	
	temp->data = x;
	
	temp->next = NULL;
	
	node** cur = head;
	
	while(*cur)
	cur = &((*cur)->next);
	
	*cur = temp;
}

int func(node* head , int k)
{
	node* temp1 = head;
	
	int i = 1;
	
	for(node* temp2 = head ; temp2 ; temp2 = temp2->next)
	{
		if(i % k == 0 && i > k)
		temp1 = temp1->next;
			
		i++;
	}
	
	return temp1->data;
}

void print(node* head)
{
	while(head)
	{
		cout << head->data << " ";

		head = head->next;
	}
	
	cout << endl << endl;
}

int main()
{
	node* head = NULL;

	insert(&head , 1);
	insert(&head , 2);
	insert(&head , 3);
	insert(&head , 4);
	insert(&head , 5);
	insert(&head , 6);
	insert(&head , 7);
	
	print(head);
	
	int k = 2;
	
	cout << "n/k th element : " << func(head , k) << endl;
	
	return 0;
}
