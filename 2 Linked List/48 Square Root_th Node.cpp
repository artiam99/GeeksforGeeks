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

int sqrth(node* head)
{
	node* temp1 = head;

	node* temp2 = head;

	int k = 1;

	while(1)
	{
		int l = k * k;
		
		int r = (k+1) * (k+1) - 1;
		
		for(int i = l ; temp1->next && i < r ; i++)
		temp1 = temp1->next;
		
		if(!temp1->next)
		return temp2->data;
		
		temp2 = temp2->next;
		temp1 = temp1->next;
		
		k++;
	}
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

	insert(&head , 1);
	insert(&head , 2);
	insert(&head , 3);
	insert(&head , 4);
	insert(&head , 5);
	insert(&head , 6);
	insert(&head , 7);
	insert(&head , 8);
	insert(&head , 9);
	insert(&head , 10);
	insert(&head , 11);
	insert(&head , 12);
	insert(&head , 13);
	insert(&head , 14);
	insert(&head , 15);
	insert(&head , 16);
	
	print(head);
	
	cout << sqrth(head) << endl;
	
	return 0;
}
