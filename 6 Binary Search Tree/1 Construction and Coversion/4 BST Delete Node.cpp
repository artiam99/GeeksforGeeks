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
	
	if(root->data==key)
	return root;
	
	else if(root->data>key)
	root->left=Insert(root->left,key);
	
	else
	root->right=Insert(root->right,key);
}
Node* deleteNode(Node* root,int key)
{
	if(!root)
	return NULL;
	
	if(root->data>key)
	root->left=deleteNode(root->left,key);
	
	else if(root->data<key)
	root->right=deleteNode(root->right,key);
	
	else
	{
		if(!root->left)
		{
			Node* temp=root->right;
			delete root;
			return temp;
		}
		
		else if(!root->right)
		{
			Node* temp=root->left;
			delete root;
			return temp;
		}
		
		else
		{
			Node* succ=root->right;
			while(succ->left)
			succ=succ->left;
			
			root->data=succ->data;
			delete succ;
			
			root->right=deleteNode(root->right,root->data);
		}
	}
	return root;
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
    
	inorder(root);cout<<endl<<endl;
	
	cout<<"Delete 40"<<endl<<endl;
	root=deleteNode(root,40);
	inorder(root);cout<<endl<<endl;
	
	cout<<"Delete 60"<<endl<<endl;
	root=deleteNode(root,60);
	inorder(root);cout<<endl;
	
	return 0;
}
