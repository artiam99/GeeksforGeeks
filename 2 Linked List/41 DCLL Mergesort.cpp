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
		
		temp->next = temp;
		
		temp->prev = temp;
		
		return head;
	}
	
	temp->prev = head->prev;
	
	head->prev->next = temp;
	
	temp->next = head;
	
	head->prev = temp;
	
	return head;
}

node* reverseit(node* head)
{
	node* prev = head->prev , *cur = head , *next;

	do
	{
		next = cur->next;

		cur->next = prev;

		cur->prev = next;

		prev = cur;

		cur = next;

	}while(cur != head);

	return prev;
}

node* findmid(node* left , node* right)
{
	node* slow = left;
	
	node* fast = left->next;
	
	while(fast != right)
	{
		fast = fast->next;
		
		if(fast != right)
		{
			fast = fast->next;
			
			slow = slow->next;
		}
	}
	
	return slow->next;
}

node* merge(node* first , node* second) 
{ 
    if (!first)
    return second; 
  
    if (!second) 
    return first; 
  
    if (first->data < second->data)
	{ 
        first->next = merge(first->next , second); 
        
		first->next->prev = first; 
        
		first->prev = NULL; 
        
		return first; 
    }
    
    else
	{ 
        second->next = merge(first , second->next); 
    
	    second->next->prev = second; 
    
	    second->prev = NULL; 
    
	    return second; 
    } 
} 

node* mergeUtil(node* head1 , node* head2) 
{ 
    if (!head1) 
    return head2; 
    
    if (!head2) 
    return head1; 
    
    node* last_node; 
    
    if (head1->prev->data < head2->prev->data) 
    last_node = head2->prev; 
    
    else
    last_node = head1->prev; 
  
    head1->prev->next = head2->prev->next = NULL; 

    node* finalHead = merge(head1, head2); 
  
    finalHead->prev = last_node; 
    last_node->next = finalHead; 
  
    return finalHead; 
}

node* mergesort(node* left , node* right)
{
	if(!left)
	return left;

	if(left->next != right)
	{
		
		node* mid = findmid(left , right);
	
		node* l = mergesort(left , mid);
		
		node* r = mergesort(mid , right);
	
		return mergeUtil(l , r);
	}
	
	left->next = left;
	
	left->prev = left;
	
	return left;
}

void print(node* head)
{
	if(head == NULL)
	return;

	node* temp = head;
	
	do
	{
		cout << temp->data << " ";
	
		temp = temp->next;
	
	}while(temp != head);
	
	cout << endl;
	
	temp = head->prev;

	do
	{
		cout << temp->data << " ";

		temp = temp->prev;
		
	}while(temp != head->prev);
	
	cout << endl << endl;
}

int main() 
{
	node* head = NULL;

	head = insert(5 , head);
	head = insert(1 , head);
	head = insert(4 , head);
	head = insert(2 , head);
	head = insert(3 , head);
	
	print(head);
	
	head = mergesort(head , head);
	
	print(head);
	
	return 0;
}

