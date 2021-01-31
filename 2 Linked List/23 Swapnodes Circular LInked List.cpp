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
	
	if(head == NULL)
	{
		temp->next = temp;
		
		head = temp;
		
		return head;
	}
	
	node* temp1 = head;
	
	do
	{
		temp1 = temp1->next;
		
	}while(temp1->next != head);
	
	temp1->next = temp;
	
	temp->next = head;
	
	return head;
}

void swapnodes(node** head , int x , int y)
{
	node* curx = *head;
	
	node* prevx = NULL;
	
	do
	{
		if(curx->data == x)
		break;
	
		prevx = curx;
		
		curx = curx->next;
	
	}while(curx != *head);
	
	node* cury = *head;
	
	node* prevy = NULL;
	
	do
	{
		if(cury->data == y)
		break;
		
		prevy = cury;
		
		cury = cury->next;
		
	}while(cury != *head);
	
	if(curx->data != x || cury->data != y)
	return;
	
	if(prevx == NULL)
	{
		node* temp = *head;
		
		do
		{
			temp = temp->next;
		
		}while(temp->next != *head);
		
		prevx = temp;
	}
	
	if(prevy == NULL)
	{
		node* temp = *head;
		
		do
		{
			temp = temp->next;
		
		}while(temp->next != *head);
		
		prevy = temp;
	}
	
	prevx->next = cury;
	
	prevy->next = curx;
	
	swap(curx->next , cury->next);
	
	if(curx == *head)
	*head = cury;
	
	else if(cury == *head)
	*head = curx;
}

void print(node* head)
{
	node* temp = head;

	do
	{
		cout << temp->data << " ";
		
		temp = temp->next;
		
	}while(temp != head);
	
	cout << endl;
}

int main() 
{
	node* head = NULL;
	
	head = insert(1 , head);
	head = insert(2 , head);
	head = insert(3 , head);
	head = insert(4 , head);
	head = insert(5 , head);
	
	print(head);
	
	swapnodes(&head , 1 , 2);
	
	print(head);
	
	swapnodes(&head , 5 , 4);
	
	print(head);
	
	swapnodes(&head , 3 , 4);
	
	print(head);
	
	swapnodes(&head , 1 , 5);
	
	print(head);
	
	return 0;
}

