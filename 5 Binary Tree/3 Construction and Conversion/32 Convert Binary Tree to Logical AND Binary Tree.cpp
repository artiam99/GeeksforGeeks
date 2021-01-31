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
void convert(Node* root)
{
	if(!root)
	return;
	
	convert(root->left);
	convert(root->right);
	
	if(root->left&&root->right)
	root->data=(root->left->data & root->right->data);
}
signed main()
{
	Node *root=new Node(0);
    root->left=new Node(1);
    root->right=new Node(0);
    root->left->left=new Node(0);
    root->left->right=new Node(1);
    root->right->left=new Node(1);
    root->right->right=new Node(1);
  
    inorder(root);
    
    convert(root);cout<<endl<<endl;
    
    inorder(root);
	
	return 0;
}
