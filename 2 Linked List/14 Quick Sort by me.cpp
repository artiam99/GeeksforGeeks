#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;

	node* next;
};

node* insert(int x , node* head)
{
	node* temp = new node;
	
	temp->data = x;
	
	temp->next = NULL;
	
	if(!head)
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

node* part(node* r , node** left , node** right)
{
	node* temp = *left;
	
	node* k = *left;
	
	while(temp->next != *right)
	{
		if(temp->data < r->data)
		{
			swap(k->data , temp->data);
			
			k = k->next;
		}
		
		temp = temp->next;
	}
	swap(r->data , k->data);
	
	return k;
}

node* randpart(node** left , node** right)
{
	node* temp = *left;
	
	int c = 1;
	
	while(temp->next != *right)
	{
		c++;
		
		temp = temp->next;
	}
	
	node* temp1 = *left;
	
	int n = rand() % c + 1;
	
	for(int i = 0 ; i < n-1 ; i++)
	temp1 = temp1->next;
	
	swap(temp->data , temp1->data);
	
	return part(temp , left , right);
}

void quicksort(node** left , node** right)
{
	if(!*left || *left == *right)
	return;
	
	if((*left)->next != *right)
	{
		node* p = randpart(left , right);
		
		quicksort(left , &p);
		
		quicksort(&(p->next) , right);
	}
}

void quick_sort(node** head)
{
	srand(time(NULL));

	node* temp = NULL;

	quicksort(head , &temp);
}

int main() 
{
	node* head = NULL;

	head = insert(6 , head);
	head = insert(3 , head);
	head = insert(4 , head);
	head = insert(5 , head);
	head = insert(2 , head);
	head = insert(3 , head);
	head = insert(4 , head);
	head = insert(5 , head);
	
	print(head);
	
	quick_sort(&head);
	
	print(head);
	
	return 0; 
}
