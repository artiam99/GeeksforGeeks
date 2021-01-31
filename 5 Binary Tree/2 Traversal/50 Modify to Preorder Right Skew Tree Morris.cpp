#include<bits/stdc++.h>
using namespace std;
#define int uint64_t
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
void insert(int x,Node** root)
{
	if(!(*root))
	{
		Node* temp=new Node(x);
		*root=temp;
		return;
	}
	if(x<=(*root)->data)
	insert(x,&((*root)->left));
	else if(x>(*root)->data)
	insert(x,&((*root)->right));
}

void preorder(Node* root)
{
	if(!root)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Node* modify(Node* root)
{
	Node* curr=root,*pre;
	while(curr)
	{
		if(!curr->left)
			curr=curr->right;
		
		else
		{
			pre=curr->left;
			while(pre->right)
			pre=pre->right;
			
			pre->right=curr->right;
			
			curr->right=curr->left;
			
			curr->left=NULL;
			
			curr=curr->right;
		}
	}
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
    preorder(root);cout<<endl;
    modify(root);
    while(root)
    {
    	cout<<root->data<<" ";
    	root=root->right;
	}
	return 0;
}
