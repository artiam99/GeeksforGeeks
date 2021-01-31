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
	
	bool lthread;
	bool rthread;
};
Node* insert(Node* root,int key)
{
	Node* temp=new Node;
	temp->data=key;
	temp->left=temp->right=NULL;
	temp->lthread=temp->rthread=0;
	
	if(!root)
	return temp;
	
	while(1)
	{
		if(root->data > key)
		{
			if(root->lthread || !root->left)
			{
				if(root->lthread)
				{
					temp->left=root->left;
					root->lthread=0;
					temp->lthread=1;
				}
				root->left=temp;
				temp->right=root;
				temp->rthread=1;
				break;
			}
			else
			root=root->left;
		}
		else if(root->data < key)
		{
			if(root->rthread || !root->right)
			{
				if(root->rthread)
				{
					temp->right=root->right;
					root->rthread=0;
					temp->rthread=1;
				}
				root->right=temp;
				temp->left=root;
				temp->lthread=1;
				break;
			}
			else
			root=root->right;
		}
		else
		break;
	}
	return root;
}
void inorder(Node* root)
{
	while(root->left)
	root=root->left;
	
	while(root)
	{
		cout<<root->data<<" ";
		
		if(root->rthread || !root->right)
		root=root->right;
		
		else
		{
			root=root->right;
			
			while(root->left && !root->lthread)
			root=root->left;
		}
	}
}
signed main()
{
	Node* root=NULL;
	
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);
    
    inorder(root);
	
	return 0;
}
