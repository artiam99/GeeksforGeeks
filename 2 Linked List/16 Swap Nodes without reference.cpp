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

void swapnode(node** head , int x , int y)
{
	if(x == y)
	return;
	
	node* curx = *head;
	
	node* prevx = NULL;
	
	while(curx && curx->data != x)
	{
		prevx = curx;
		
		curx = curx->next;
	}
	
	node* cury = *head;
	
	node* prevy = NULL;
	
	while(cury && cury->data != y)
	{
		prevy = cury;
		
		cury = cury->next;
	}
	
	if(prevx == NULL)
	*head = cury;
	
	else
	prevx->next = cury;
	
	if(prevy == NULL)
	*head = curx;
	
	else
	prevy->next = curx;
	
	swap(curx->next , cury->next);
}

int main() 
{
	node* head = NULL;
	
	head = insert(2 , 0 , head);
	head = insert(3 , 1 , head);
	head = insert(4 , 2 , head);
	head = insert(5 , 3 , head);
	
	print(head);
	
	swapnode(&head , 2 , 5);
	
	print(head);
	
	return 0; 
}
