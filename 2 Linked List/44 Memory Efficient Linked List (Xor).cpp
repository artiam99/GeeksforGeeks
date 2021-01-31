#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;

	node *npx;
};

node* Xor(node* prev , node* next)
{
	return (node*)(((uintptr_t)prev)^((uintptr_t)next));
}

node* insertbegin(node* head , int x)
{
	node* temp = new node();
	
	temp->data = x;
	
	temp->npx = head;
	
	if(head)
	head->npx = Xor(head->npx , temp);
	
	head = temp;
	
	return head;
}

node* insertend(node* head , int x)
{
	node* temp = new node();
	
	temp->data = x;
	
	temp->npx = NULL;
	
	if(head == NULL)
	{
		head = temp;
		
		return head;
	}
	
	node* cur = head;
	
	node* prev = NULL;
	
	node* next;
	
	while(cur->npx != prev)
	{
		next = Xor(cur->npx , prev);
		
		prev = cur;
		
		cur = next;
	}
	
	temp->npx = cur;
	
	cur->npx = Xor(cur->npx , temp);
	
	return head;
}

node* insertafter(node* head , int y , int x)
{
	node* temp = new node();

	temp->data = x;

	temp->npx = NULL;

	node* cur = head;

	node* prev = NULL;

	node* next;

	while(cur && cur->data != y)
	{
		next = Xor(cur->npx , prev);
		
		prev = cur;
		
		cur = next;
	}
	
	if(!cur)
	return head;
	
	next = Xor(cur->npx , prev);
	
	if(next)
	next->npx = Xor(Xor(next->npx , cur) , temp);
	
	cur->npx = Xor(Xor(cur->npx , next) , temp);
	
	temp->npx = Xor(cur , next);

	return head;
}

node* insertbefore(node* head , int y , int x)
{
	node* temp = new node();

	temp->data = x;

	temp->npx = NULL;

	node* cur = head;

	node* prev = NULL;

	node* next;

	while(cur && cur->data != y)
	{
		next = Xor(cur->npx , prev);
		
		prev = cur;
		
		cur = next;
	}
	
	cur->npx = Xor(Xor(cur->npx , prev) , temp);
	
	if(prev)
	prev->npx = Xor(Xor(prev->npx , cur) , temp);
	
	else
	head = temp;
	temp->npx = Xor(cur , prev);
	
	return head;
}

node* deletion(node* head , int x)
{
	node* cur = head;
	
	node* prev = NULL;
	
	node* next;
	
	while(cur && cur->data != x)
	{
		next = Xor(cur->npx , prev);
		
		prev = cur;
		
		cur = next;
	}
	
	if(!cur)
	return head;
	
	next = Xor(cur->npx , prev);
	
	if(next)
	next->npx = Xor(Xor(next->npx , cur) , prev);
	
	if(prev)
	prev->npx = Xor(Xor(prev->npx , cur) , next);
	
	else
	head = next;
	
	delete cur;
	
	return head;
}

node* reverse(node* head)
{
	node* cur = head;

	node* prev = NULL;

	node* next;

	while(cur)
	{
		next = Xor(cur->npx , prev);

		prev = cur;

		cur = next;
	}
	
	return prev;
}

void print(node* head)
{
	node* cur = head;
	
	node* prev = NULL;
	
	node* next;
	
	while(cur)
	{
		cout << cur->data << " ";
		
		next = Xor(cur->npx , prev);
		
		prev = cur;
		
		cur = next;
	}
	
	cout << endl;
	
	cur = prev;
	
	next = NULL;
	
	while(cur)
	{
		cout << cur->data << " ";
		
		prev = Xor(cur->npx , next);
		
		next = cur;
		
		cur = prev;
	}
	
	cout << endl << endl;
}

int main()
{
	node* head = NULL;

	head = insertbegin(head , 3);
	head = insertbegin(head , 2);
	head = insertend(head , 6);
	head = insertafter(head , 3 , 4);
    head = insertbefore(head , 6 , 5);
    head = insertbefore(head , 2 , 1);
    head = insertafter(head , 6 , 7);

	print(head);

	head = reverse(head);

	print(head);
	
	head = deletion(head , 1);
	head = deletion(head , 4);
	head = deletion(head , 7);
	
	print(head);
	
	return 0;
}

