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
void find(Node* root,Node* curr,Node* &parent,int &plvl,int h=0)
{
	h++;
	if(!root)
	return;
	
	if(root->left==curr)
	{
		parent=root;
		plvl=h;
		return;
	}
	else if(root->right==curr)
	{
		parent=root;
		plvl=h;
		return;
	}
	if(plvl==-1)
	find(root->left,curr,parent,plvl,h);
	
	if(plvl==-1)
	find(root->right,curr,parent,plvl,h);
}
void print(Node* root,Node* parent,int plvl)
{
	if(!root)
	return;

	if(plvl==1)
	{
		if(root!=parent)
		{
			if(root->left)
			cout<<root->left->data<<" ";
			if(root->right)
			cout<<root->right->data<<" ";
		}
		return;
	}

	print(root->left,parent,plvl-1);
	print(root->right,parent,plvl-1);
}
void printCousins(Node* root,Node* curr)
{
	Node* parent=NULL;
	
	int plvl=-1;
	
	if(root!=curr)
	find(root,curr,parent,plvl);
	
	print(root,parent,plvl);
}
signed main()
{
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->right = new Node(15); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
  
    printCousins(root, root->left->right);
    
    return 0; 
}
