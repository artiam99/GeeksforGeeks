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
Node* insert(Node* root,int key)
{
    if (root == NULL)
    return new Node(key);
    
	if (root->data > key)
    root->left = insert(root->left, key);
    
	else
    root->right = insert(root->right, key);
    
	return root;
}
void inorder(Node* root)
{
	if(!root)
	return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* DeleteTree(Node* root)
{
	if(!root)
	return NULL;
	
	root->left=DeleteTree(root->left);
	root->right=DeleteTree(root->right);
	
	if(!root->left && !root->right)
	delete root;
	
	return NULL;
}
Node* removeOutsideRange(Node* root,int l,int r)
{
	if(!root)
	return NULL;
	
	if(root->data >=l && root->data <=r)
	{
		root->left=removeOutsideRange(root->left,l,r);
		root->right=removeOutsideRange(root->right,l,r);
		return root;
	}
	else if(root->data < l)
	{
		Node* right=root->right;
		root->right=NULL;
		DeleteTree(root);
		return removeOutsideRange(right,l,r);
	}
	
	else if(root->data > r)
	{
		Node* left=root->left;
		root->left=NULL;
		DeleteTree(root);
		return removeOutsideRange(left,l,r);
	}
}
signed main()
{
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);

    cout << "Inorder traversal of the given tree is: ";
    inorder(root);

    root = removeOutsideRange(root, -10, 13);

    cout << "\nInorder traversal of the modified tree is: ";
    inorder(root);
    
    return 0;
}
