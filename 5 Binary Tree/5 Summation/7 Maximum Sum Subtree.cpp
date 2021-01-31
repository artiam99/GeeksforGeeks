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
int traverse(Node* root,int &mx)
{
	if(!root)
	return 0;
	
	int l=traverse(root->left,mx);
	int r=traverse(root->right,mx);
	
	mx=max(mx,l+r+root->data);
	
	return l+r+root->data;
}
int MaxSumSubtree(Node* root)
{
	int mx=intmin;
	traverse(root,mx);
	return mx;
}
signed main()
{
	Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    cout << MaxSumSubtree(root);
    
    return 0; 
}
