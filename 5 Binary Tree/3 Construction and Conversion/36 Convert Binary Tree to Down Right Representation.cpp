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
void downRightTraversal(Node *root) 
{ 
    if (root != NULL) 
    { 
        cout <<root->data<< " "; 
        downRightTraversal(root->right); 
        downRightTraversal(root->left); 
    } 
}
void convert(Node* root)
{
	if(!root)
	return;
	
	convert(root->left);
	convert(root->right);
	
	if(!root->left)
	root->left=root->right;
	
	else
	root->left->right=root->right;
	
	root->right=NULL;
}
signed main()
{
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->right->left = new Node(4); 
    root->right->right = new Node(5); 
    root->right->left->left = new Node(6); 
    root->right->right->left = new Node(7); 
    root->right->right->right = new Node(8); 
	
	convert(root);
	
	downRightTraversal(root);
	
	return 0;
}
