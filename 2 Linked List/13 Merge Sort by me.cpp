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

node* findmid(node* left , node* right)
{
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
    
    slow = slow->next;
    
	return slow;
}

node* merge(node* head1 , node* head2)
{
    if(head1 == NULL)
    return head2;
    
    else if(head2 == NULL)
    return head1;
    
	node* head = NULL;
    if(head1->data < head2->data)
    {
        head = head1;
        head->next = merge(head1->next,head2);
    }
    
    else
    {
        head = head2;
        
        head->next = merge(head1 , head2->next);
    }
    
    return head;
}

node* msort(node* left , node* right)
{
	if(!left)
	return left;
	
    if(left->next != right)
    {
        node* mid = findmid(left , right);
        
        node* l = msort(left , mid);
        
        node* r = msort(mid , right);
        
		return merge(l , r);
    }
    
    left->next = NULL;
    
	return left;
}

node* mergeSort(node* head)
{
    return msort(head , NULL);
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
	
	head = mergeSort(head);
	
	print(head);
	
	return 0; 
}

