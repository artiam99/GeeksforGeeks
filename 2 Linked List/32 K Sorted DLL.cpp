#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;

    node* prev;

	node* next;	
};

node* getnode(int x)
{
	node* temp = new node();

	temp->data = x;

	temp->next = NULL;

	temp->prev = NULL;

	return temp;
}

node* insert(int x , node* head)
{
	node* temp = getnode(x);
	
	if(head == NULL)
	{
		head = temp;

		return head;
	}
	
	node* temp1 = head;

	while(temp1->next != NULL)
	temp1 = temp1->next;

	temp->prev = temp1;

	temp1->next = temp;

	return head;
}

void sortlist(int k , node* head)
{
	node* temp = head;
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i = 0 ; i < k ; i++)
	{
		pq.push(temp->data);
		
		temp = temp->next;
	}
	
	node* temp1 = head;
	
	while(!pq.empty())
	{
		temp1->data = pq.top();
		
		pq.pop();
		
		temp1 = temp1->next;
		
		if(temp != NULL)
		{
			pq.push(temp->data);
			
			temp = temp->next;
		}
	}
}

void print(node* head)
{
	node* temp = head;
	
	node* temp1;
	
	while(temp != NULL)
	{
		temp1 = temp;
		
		cout << temp->data << " ";
		
		temp = temp->next;
	}
	
	cout << endl;
	
	while(temp1 != NULL)
	{
		cout << temp1->data << " ";
		
		temp1 = temp1->prev;
	}
	cout << endl << endl;
}

int main() 
{
	node* head = NULL;
	
	head = insert(3 , head);
	head = insert(6 , head);
	head = insert(2 , head);
	head = insert(12 , head);
	head = insert(56 , head);
	head = insert(8 , head);
	
	int k = 3;
	
	print(head);
	
	sortlist(k , head);
	
	print(head);
	
	return 0;
}

