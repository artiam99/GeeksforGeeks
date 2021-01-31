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
Node* Insert(Node* root,int key)
{
	if(!root)
	return new Node(key);
	
	Node* curr=root;
	while(1)
	{
		
		if(curr->data==key)
		return root;
		
		else if(curr->data>key)
		{
			if(!curr->left)
		    {
		    	curr->left=new Node(key);
		    	return root;
			}
			curr=curr->left;
		}
		else
		{
			if(!curr->right)
			{
				curr->right=new Node(key);
				return root;
			}
			curr=curr->right;
		}
	}
}
signed main()
{
	Node* root=NULL;
	
	root=Insert(root,30);
    root=Insert(root,20);
    root=Insert(root,40);
    root=Insert(root,70);
    root=Insert(root,60);
    root=Insert(root,80);
    
	inorder(root);
	
	return 0;
}
