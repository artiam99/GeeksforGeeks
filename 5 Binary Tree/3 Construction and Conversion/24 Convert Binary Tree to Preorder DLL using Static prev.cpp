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
void preorder(Node* root)
{
	if(!root)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void BTtoDLL(Node* root)
{
	static Node* prev=NULL;
	
	if(!root)
	return;
	
	Node* left=root->left;
	Node* right=root->right;
	
	if(prev)
	prev->right=root;
	
	root->left=prev;
	
	prev=root;
	
	BTtoDLL(left);
	BTtoDLL(right);
	
}
signed main()
{
	Node *root = new Node(10);  
    root->left = new Node(12);  
    root->right = new Node(15);  
    root->left->left = new Node(25);  
    root->left->right = new Node(30);  
    root->right->left = new Node(36);
    
    preorder(root);cout<<endl<<endl;
    
    Node* head=root;
	
	BTtoDLL(root);
    
	print_list(head);
	
	return 0;
}
