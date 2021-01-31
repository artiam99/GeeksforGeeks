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
	
	if(!head)
	{
		temp->next = temp;
	
		head = temp;
	
		return head;
	}
	
	node* temp1 = head;
	
	while(temp1->next != head)
	temp1 = temp1->next;
	
	temp1->next = temp;
	
	temp->next = head;
	
	return head;
}

int josephus(int n , int k)
{
	node* head = NULL;
	
	for(int i = 1 ; i <= n ; i++)
	head = insert(i , head);
	
	node* prev = head;
	
	while(prev->next != head)
	prev = prev->next;
	
	while(head->next != head)
	{
		for(int i = 0 ; i < k-1 ; i++)
		{
			prev = head;
			
			head = head->next;
		}
		
		prev->next = head->next;
		
		delete head;
		
		head = prev->next;
	}
	
	int x = head->data;
	
	delete head;
	
	return x;
}

int main() 
{
	int n = 4 , m = 2;
	
	cout << josephus(n , m) << endl;
	
	n = 2 ; m = 1;
	
	cout << josephus(n , m) << endl;;
	
	n = 4 ; m = 2;
	
	cout << josephus(n , m) << endl;
	
	n = 50 ; m = 10;
	
	cout << josephus(n , m) << endl;
	
	return 0;
}

