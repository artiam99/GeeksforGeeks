#include<bits/stdc++.h>
using namespace std;
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
void Print(Node* root,int k1,int k2)
{
	if(!root)
	return;
	
	if(root->data >k1)
	Print(root->left,k1,k2);
	
	if(root->data >=k1 && root->data<=k2)
	cout<<root->data<<" ";
	
	if(root->data < k2)
	Print(root->right,k1,k2);
}
signed main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    
    int k1 = 10, k2 = 25;
    
    Print(root, k1, k2);  
    return 0;
}
