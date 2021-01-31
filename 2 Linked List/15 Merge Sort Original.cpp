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

void findmid(node* head , node** left , node** right) 
{
    node* slow = head; 
    
	node* fast = head->next;
    
	while (fast)
	{ 
        fast = fast->next;
        
		if(fast)
		{
            slow = slow->next;
        
		    fast = fast->next;
        }
    }
    
    *left = head; 
  
    *right = slow->next; 
  
    slow->next = NULL; 
}

node* merge(node* head1 , node* head2) 
{     
    if(!head1) 
    return head2; 
    
    else if(!head2) 
    return head1; 
    
	node* head = NULL;
   
    if(head1->data < head2->data)
	{ 
        head = head1;
        
		head->next = merge(head1->next , head2); 
    }

    else
	{ 
        head = head2;
		 
        head->next = merge(head1 , head2->next);
    }
    
    return head;
}

void merge_sort(node** headRef) 
{ 
    node* head = *headRef; 

    node* left;
    
    node* right;
    
	if(!head || !head->next)
    return;
   
    findmid(head , &left , &right);
    
	merge_sort(&left);
    
    merge_sort(&right);
    
	*headRef = merge(left , right); 
}

int main() 
{
	node* head = NULL;
	
	head = insert(1 , head);
	head = insert(2 , head);
	head = insert(3 , head);
	head = insert(4 , head);
	head = insert(5 , head);
	head = insert(6 , head);
	head = insert(7 , head);
    head = insert(8 , head);
	
	print(head);
	
	merge_sort(&head);
	
	print(head);
	
	return 0; 
}
