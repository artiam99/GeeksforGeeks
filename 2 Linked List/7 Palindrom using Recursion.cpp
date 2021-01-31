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

bool ispalindromuntill(node* &left , node* right)
{
	if(right == NULL)
	return true;
	
	bool i = ispalindromuntill(left , right->next);
	
	if(i == false)
	return false;
	
	i = (left->data == right->data);
	
	left = left->next;
	
	return i;
}

void ispalindrom(node* head)
{
	if(ispalindromuntill(head , head))
	cout << "Palindrom" << endl;
	
	else
	cout << "Not Palindrom" << endl;
}

int main() 
{
	node* head1 = NULL;
	node* head2 = NULL;
	node* head3 = NULL;
	node* head4 = NULL;
	
	head1 = insert(2 , 0 , head1);
	head1 = insert(3 , 0 , head1);
	head1 = insert(4 , 2 , head1);
	head1 = insert(5 , 2 , head1);
	
	print(head1);
	
	ispalindrom(head1);
	
	head2 = insert(2 , 0 , head2);
	head2 = insert(4 , 1 , head2);
	head2 = insert(4 , 2 , head2);
	head2 = insert(2 , 3 , head2);

	print(head2);

	ispalindrom(head2);

	head3 = insert(5 , 0 , head3);
	head3 = insert(3 , 1 , head3);
	head3 = insert(4 , 2 , head3);
	head3 = insert(3 , 3 , head3);
	head3 = insert(5 , 4 , head3);
	
	print(head3);
	
	ispalindrom(head3);
	
	head4 = insert(5 , 0 , head4);
	
	print(head4);
	
	ispalindrom(head4);
	
	return 0;
}

