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
void traverse(Node* slow,Node* fast)
{
	if(!fast->left||!fast->left->left)
	{
		cout<<slow->data<<" ";
		return;
	}
	
	traverse(slow->left,fast->left->left);
	traverse(slow->right,fast->left->left);
}
void Print_middle(Node* root)
{
	if(!root)
	return;
	
	Node* slow=root;
	Node* fast=root;
	traverse(slow,fast);
}
signed main()
{
	Node* root = NULL; 
    root = new Node(10); 
    root->left = new Node(20); 
    root->right = new Node(30); 
  
    root->left->left = new Node(40); 
    root->left->right = new Node(50); 
    root->right->left = new Node(60); 
    root->right->right = new Node(70); 
    
    Print_middle(root);
    
    return 0; 
}
