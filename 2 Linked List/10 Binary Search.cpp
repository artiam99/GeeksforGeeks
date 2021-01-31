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

node* findmid(node* left , node* right)
{
	if(left == NULL)
	return NULL;

	node* slow = left;
	
	node* fast = left->next;

	while(fast != right)
	{
		fast = fast->next;

		if(fast != right)
		{
			slow = slow->next;
			
			fast = fast->next;
	    }
	}
	
	return slow;
}

node* binarysearch(node* head , int x)
{
	node* left = head;
	
	node* right = NULL;
	
	while(left != right)
	{
		node* mid = findmid(left , right);
		
		if(mid == NULL)
		return NULL;
		
		if(mid->data == x)
		return mid;
		
		else if(mid->data < x)
		left = mid->next;
		
		else
		right = mid;
	}
	
	return NULL;
}

int main() 
{
	srand(time(NULL));
	
	node* head = NULL;
	
	head = insert(2 , 0 , head);
	head = insert(3 , 1 , head);
	head = insert(4 , 2 , head);
	head = insert(5 , 3 , head);
	
	print(head);
	
	int x = rand() % 8;
	
	node* find = binarysearch(head,x);
	
	if(find)
	cout << x << " was found" << endl;
	
	else
	cout << x << " wasn't found" << endl;
	
	return 0; 
}
