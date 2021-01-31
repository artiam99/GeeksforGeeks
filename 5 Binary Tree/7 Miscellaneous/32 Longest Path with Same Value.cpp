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
int traverse(Node* root,int &ans)
{
	if(!root)
	return 0;
	
	int left=traverse(root->left,ans);
	int right=traverse(root->right,ans);
	
	
	int leftmax=0,rightmax=0;
	
	if(root->left && root->left->data == root->data)
	leftmax=left+1;
	
	if(root->right && root->right->data == root->data)
	rightmax=right+1;
	
	ans=max(ans,leftmax+rightmax);
	
	return max(leftmax,rightmax);
}
int longestSameValuePath(Node* root)
{
	int ans=0;
	traverse(root,ans);
	return ans;
}
signed main()
{
	/*
	    4 
	   / \ 
	  4   4 
	 / \   \ 
	4   9   5 */
	
	Node *root = new Node(4);
	root->left = new Node(4);
	root->right = new Node(4);
	root->left->left = new Node(4);
	root->left->right = new Node(9);
	root->right->right = new Node(5);
	
	cout << longestSameValuePath(root);
	
	return 0;
}
