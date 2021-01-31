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
int minDepth(Node* root)
{
	if(!root)
	return 0;
	
	if(!root->left && !root->right)
	return 1;

	if(!root->left)
	return minDepth(root->right)+1;
	
	if(!root->right)
	return minDepth(root->left)+1;
	
	return min(minDepth(root->left),minDepth(root->right))+1;
}
signed main()
{
    Node *root     = new Node(1);
    root->left     = new Node(2);
    root->right     = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout <<"The minimum depth of binary tree is : "<< minDepth(root);
    return 0;
}
