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
	{
		int sum=root->left->data+root->right->data;
		if(sum>=root->data)
		root->data=sum;
		else
		{
			root->left->data+=root->data-sum;
			convert(root->left);
		}
	}
}
signed main()
{
	Node *root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);
  
    inorder(root);
    
    convert(root);cout<<endl<<endl;
    
    inorder(root);
	
	return 0;
}
