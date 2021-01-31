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

node* maxsumLL(node* head1 , node* head2)
{
	node* head = NULL;

	node* cur1 = head1;

	node* cur2 = head2;

	node* h = NULL;

	while(cur1 && cur2)
	{
		int sum1 = 0 , sum2 = 0;
		
		node* temp1 = cur1 , *temp2 = cur2;
		
		while(temp1 && temp2 && temp1->data != temp2->data)
		{
			if(temp1->data < temp2->data)
			{
				sum1 += temp1->data;
			
				temp1 = temp1->next;
			}
			
			else
			{
				sum2 += temp2->data;
			
				temp2 = temp2->next;
			}
		}
		
		if(!temp1)
		{
			while(temp2)
			{
				sum2 += temp2->data;
		
				temp2 = temp2->next;
			}
		}
		
		if(!temp2)
		{
			while(temp1)
			{
				sum1 += temp1->data;
		
				temp1 = temp1->next;
			}
		}
		
		if(sum1 > sum2)
		{
			if(head == NULL)
			head = cur1;
		
			else
			h->next = cur1;
		
			h = temp1;
		}
		
		else
		{
			if(head == NULL)
			head = cur2;
			
			else
			h->next = cur2;
			
			h = temp2;
		}
		
		cur1 = (temp1 ? temp1->next : temp1);
		cur2 = (temp2 ? temp2->next : temp2);
	}
	
	return head;
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
	node* head1 = NULL;

	insert(&head1 , 1);
	insert(&head1 , 3);
	insert(&head1 , 30);
	insert(&head1 , 90);
	insert(&head1 , 120);
	insert(&head1 , 240);
	insert(&head1 , 511);

	print(head1);

	node* head2 = NULL;

	insert(&head2 , 0);
	insert(&head2 , 3);
	insert(&head2 , 12);
	insert(&head2 , 32);
	insert(&head2 , 90);
	insert(&head2 , 125);
	insert(&head2 , 240);
	insert(&head2 , 249);

	print(head2);

	node* head = maxsumLL(head1 , head2);

	print(head);

	return 0;
}

