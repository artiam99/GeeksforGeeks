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
Node* InorderSucc(Node* root,Node* x)
{
	Node* p=NULL;// last ancestor's parent
	
	while(root && root!=x)
	{
		if(root->data < x->data)
		root=root->right;
		
		else
		{
			p=root;
			root=root->left;
		}
	}
	
	if(!root)// X not found
	return NULL;
	
	if(!root->right)// X doesn't have right child
	return p;
	
	root=root->right;// left most Node in right subtree
	
	while(root->left)
	root=root->left;
	
	return root;
}
signed main()
{
    /*
          10 
        /    \ 
      5       50 
     /       /  \ 
    1       40   100   */
	
    Node* root = new Node(10); 
    root->left = new Node(5); 
    root->right = new Node(50); 
    root->left->left = new Node(1); 
    root->right->left = new Node(40); 
    root->right->right = new Node(100); 
    
    cout<< "Inorder Successor of "<< 40 <<" : "<<InorderSucc(root,root->right->left)->data<<endl;
    
    cout<< "Inorder Successor of "<< 5 <<" : "<<InorderSucc(root,root->left)->data<<endl;
	
	return 0;
}
