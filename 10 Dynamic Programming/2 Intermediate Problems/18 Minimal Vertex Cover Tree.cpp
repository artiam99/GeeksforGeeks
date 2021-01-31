#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* left,*right;
	int vc;
	Node(int data)
	{
		this->data = data;
		
		left = right = NULL;
		
		vc = -1;
	}
};
int VertexCover(Node* root)
{
	if(!root)  return 0;
	
	if(!root->left && !root->right)  return 0;
	
	if(root->vc != -1)  return root->vc;
	
	int incl = 1 + VertexCover(root->left) + VertexCover(root->right);
	
	int excl = ((root->left) ? 1 + VertexCover(root->left->left) + VertexCover(root->left->right) : 0) + 
	           ((root->right) ? 1 + VertexCover(root->right->left) + VertexCover(root->right->right) : 0);
	           
	return root->vc = min(incl,excl);
}
signed main()
{
	Node *root         		  = new Node(20);
    root->left                = new Node(8);
    root->left->left          = new Node(4);
    root->left->right         = new Node(12);
    root->left->right->left   = new Node(10);
    root->left->right->right  = new Node(14);
    root->right               = new Node(22);
    root->right->right        = new Node(25);
    
    cout<< VertexCover(root) <<endl;
    
	return 0;
}
