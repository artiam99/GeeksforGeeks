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
int traverse(Node* root,int &maxsum)
{
	if(!root)
	return 0;
	
	if(!root->left && !root->right)
	return root->data;
	
	int l=traverse(root->left,maxsum);
	int r=traverse(root->right,maxsum);
	
	if(root->left && root->right)
	{
		maxsum=max(maxsum,l+r+root->data);
		
		return max(l,r)+root->data;
	}
	
	return root->data+((root->left)?l:r);
}
int maxPathSum(Node* root)
{
	int maxSum=intmin;
	traverse(root,maxSum);
	return maxSum;
}
signed main()
{
	Node *root = new Node(-15);
    root->left = new Node(5);
    root->right = new Node(6);
    root->left->left = new Node(-8);
    root->left->right = new Node(1);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    root->right->right->right= new Node(0);
    root->right->right->right->left= new Node(4);
    root->right->right->right->right= new Node(-1);
    root->right->right->right->right->left= new Node(10);
    
	cout << "Max pathSum of the given binary tree is "<<maxPathSum(root);
    
    return 0; 
}
