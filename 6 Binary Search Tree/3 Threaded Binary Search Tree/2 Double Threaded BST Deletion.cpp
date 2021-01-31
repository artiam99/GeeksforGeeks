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
Node* Insert(Node* root,int key)
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
Node* Deleteuntill(Node* root,Node* parent,int key)
{
	if(!root)
	return NULL;
	
	Node* curr=root;
	while(1)
	{
		if(curr->data > key)
		{
			parent=curr;
			if(curr->lthread)
			return root;
			curr=curr->left;
		}
		else if(curr->data < key)
		{
			parent=curr;
			if(curr->rthread)
			return root;
			curr=curr->right;
		}
		else
		{
			if(curr->lthread && curr->rthread)
			{
				if(!parent)
				return NULL;
				
				if(parent->left==curr)
				{
					parent->left=curr->left;
					if(curr->left)
					parent->lthread=1;
					delete curr;
				}
				else 
				{
					parent->right=curr->right;
					if(curr->right)
					parent->rthread=1;
					delete curr;
				}
				return  root;
			}
			else if(!curr->lthread)
			{
				Node* temp=curr->left;
				while(temp->right)
				temp=temp->right;
				curr->data=temp->data;
				
				curr->left=Deleteuntill(curr->left,curr,temp->data);
				return root;
			}
			else
			{
				Node* temp=curr->right;
				while(temp->left)
				temp=temp->left;
				curr->data=temp->data;
				
				curr->right=Deleteuntill(curr->right,curr,temp->data);
				return root;
			}
		}
	}
	
}
Node* Delete(Node* root,int key)
{
	return Deleteuntill(root,NULL,key);
}
void print(Node* root)
{
	Node* root1=root,*root2=root;
	
	while(root1->left)
	root1=root1->left;
	
	while(root1)
	{
		cout<<root1->data<<" ";
		
		if(root1->rthread || !root1->right)
		root1=root1->right;
		
		else
		{
			root1=root1->right;
			
			while(root1->left && !root1->lthread)
			root1=root1->left;
		}
	}
	
	cout<<endl;
	
	while(root2->right)
	root2=root2->right;
	
	while(root2)
	{
		cout<<root2->data<<" ";
		
		if(root2->lthread || !root2->left)
		root2=root2->left;
		
		else
		{
			root2=root2->left;
			
			while(root2->right && !root2->rthread)
			root2=root2->right;
		}
	}
	cout<<endl<<endl;
}
signed main()
{
	Node* root=NULL;
	
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 30);
    root = Insert(root, 5);
    root = Insert(root, 16);
    root = Insert(root, 14);
    root = Insert(root, 17);
    root = Insert(root, 13);
    
    print(root);
    
    root=Delete(root,16);
    root=Delete(root,13);
    root=Delete(root,1);
    root=Delete(root,40);
    
    print(root);
	
	return 0;
}
