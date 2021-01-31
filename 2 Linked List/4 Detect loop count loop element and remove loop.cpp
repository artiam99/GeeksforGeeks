#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	
	node* next;
};

node* insert(int x , int n , node* head)
{
	node* temp = new node;
	
	temp->data = x;
	
	temp->next = NULL;
	
	if(n == 0)
	{
		temp->next = head;
		
		head = temp;
		
		return head;
	}
	
	node* temp1 = head;
	
	for(int i = 0 ; i < n-1 ; i++)
	temp1 = temp1->next;
	
	temp->next = temp1->next;
	
	temp1->next = temp;
	
	return head;
}

void makeloop(int x , int y , node *head)
{
	node* temp1 = head;
	
	node* temp2 = head;
	
	for(int i = 0 ; i < x-1 ; i++)
	temp1 = temp1->next;
	
	for(int i = 0 ; i < y-1 ; i++)
	temp2 = temp2->next;
	
	temp2->next = temp1;
}

void detectloop(node *head)
{
	node* temp1 = head;
	
	node* temp2 = head;
	
	while(temp1 && temp2 && temp1->next)
	{
		temp1 = temp1->next->next;
		
		temp2 = temp2->next;
		
		if(temp1 == temp2)
		{
			cout << "Loop found ";
			
			int c = 1;
			
			temp2 = temp2->next;
			
			while(temp2 != temp1)
			{
				temp2 = temp2->next;
			
				c++;
			
			}
			
			cout << " : Length is " << c << endl;
			
			cout << "Loop elements : ";
			
			temp1 = head;
			
			temp2 = head;
			
			for(int i = 0 ; i < c ; i++)
			temp2 = temp2->next;
			
			while(temp1 != temp2)
			{
				temp1 = temp1->next;
			
				temp2 = temp2->next;
			}
			
			cout << temp1->data << " ";
			
			temp1 = temp1->next;
			
			while(1)
			{
				cout << temp1->data << " ";
				
				if(temp1->next == temp2)
				{
					temp1->next = NULL;
				
					break;
				}
				
				temp1 = temp1->next;
			}
			
			cout << endl << "Loop removed" << endl;
			
			cout << "Elements are : ";
			
			temp1 = head;
			
			while(temp1)
			{
				cout << temp1->data << " ";
			
				temp1 = temp1->next;
			}
			
			return;
		}
	}
	
	cout << "Loop Not found " << endl << endl;
}

int main()
{
	node* head = NULL;
	
	head = insert(2 , 0 , head);
	head = insert(3 , 0 , head);
	head = insert(4 , 2 , head);
	head = insert(5 , 2 , head);
	
	detectloop(head);
	
	makeloop(2 , 4 , head);
	
	detectloop(head);
	
	return 0; 
}

