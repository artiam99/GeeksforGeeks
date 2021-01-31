#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}
Node* merge(Node* h1, Node* h2)
{
	Node* head=NULL;
	Node** ref=&head;
	
	while(h1 && h2)
	{
		if(h1->data<h2->data)
		{
			*ref=h1;
			h1=h1->next;
		}
		else
		{
			*ref=h2;
			h2=h2->next;
		}
		
		ref=&((*ref)->next);
	}
	
	*ref=(h1)?h1:h2;
	
	return head;
}
int main()
{
	Node* head1 = newNode(1);
	head1->next = newNode(3);
	head1->next->next = newNode(5);

	Node* head2 = newNode(0);
	head2->next = newNode(2);
	head2->next->next = newNode(4);

	Node* mergedhead = merge(head1, head2);

	printList(mergedhead);
	
	return 0; 
} 

