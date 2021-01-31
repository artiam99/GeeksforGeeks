#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
void print_list(Node* head)
{
	Node* tail;
	while(head)
	{
		cout<<head->data<<" ";
		tail=head;
		head=head->right;
	}
	cout<<endl;
	while(tail)
	{
		cout<<tail->data<<" ";
		tail=tail->left;
	}
	cout<<endl;
}
void LOT(Node* root)
{
	queue<Node*> q;
	
	if(root)
	q.push(root);
	
	while(q.size())
	{
		cout<<q.front()->data<<" ";
		if(q.front()->left)
		q.push(q.front()->left);
		if(q.front()->right)
		q.push(q.front()->right);
		q.pop();
	}
}
void BTtoDLL(Node* root)
{
	queue<Node*> q;
	
	Node* prev=NULL;
	
	if(root)
	q.push(root);
	
	while(q.size())
	{
		Node* temp=q.front();
		q.pop();
		
		if(temp->left)
		q.push(temp->left);
		
		if(temp->right)
		q.push(temp->right);
		
		temp->left=prev;
		
		if(prev)
		prev->right=temp;
		
		prev=temp;
	}
}
signed main()
{
	Node *root = new Node(10);  
    root->left = new Node(12);  
    root->right = new Node(15);  
    root->left->left = new Node(25);  
    root->left->right = new Node(30);  
    root->right->left = new Node(36);
    
    LOT(root);cout<<endl<<endl;
    
    Node* head=root;
	
	BTtoDLL(root);
    
	print_list(head);
	
	return 0;
}
