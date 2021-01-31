#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* left,*right;
	int dp;
	Node(int data)
	{
		this->data = data;
		
		left = right = NULL;
		
		dp = -1;
	}
};
int LISS(Node* root)
{
	if(!root)  return 0;
	
	if(!root->left && !root->right)  return 1;
	
	if(root->dp != -1)  return root->dp;
	
	int incl = 1 + ((root->left) ? LISS(root->left->left) + LISS(root->left->right) : 0) + ((root->right) ? LISS(root->right->left) + LISS(root->right->right) : 0);
	
	int excl = LISS(root->left) + LISS(root->right);
	
	return root->dp = max(incl , excl);
}
signed main()
{
	Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);
  
    cout << "Size of the Largest Independent Set is " << LISS(root) <<endl;
    
	return 0;
}
