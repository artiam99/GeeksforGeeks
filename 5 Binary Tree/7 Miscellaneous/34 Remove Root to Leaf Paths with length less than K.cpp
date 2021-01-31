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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* traverse(Node* root,int lvl,int k)
{
	if(!root)
	return NULL;
		
	root->left=traverse(root->left,lvl+1,k);
	root->right=traverse(root->right,lvl+1,k);
	
	if(!root->left && !root->right && lvl<k)
	{
		delete root;
		return NULL;
	}
	return root;
}
void removeShortPathNodes(Node* root,int k)
{
	traverse(root,1,k);
}
signed main()
{
    int k = 4;
    
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);
    
    cout << "Inorder Traversal of Original tree" << endl; 
    inorder(root);
	cout << endl;
    
    cout << "Inorder Traversal of Modified tree" << endl;
    removeShortPathNodes(root, k);
    
    inorder(root); 
    return 0;
}
