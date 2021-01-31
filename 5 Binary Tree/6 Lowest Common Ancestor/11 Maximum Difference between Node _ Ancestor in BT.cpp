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
	{
		mx=0;
		return -1;
	}
	
	if(!root->left && !root->right)
	return root->data;
	
	int l=intmax,r=intmax;
	
	if(root->left)
	l=traverse(root->left,mx);
	
	if(root->right)
	r=traverse(root->right,mx);
	
	mx=max(mx,root->data-min(l,r));
	
	return min(root->data,min(l,r));
}
int maxDiff(Node* root)
{
	int mx=intmin;
	traverse(root,mx);
	return mx;
}
signed main()
{
	Node* root = new Node(8);
    root->left = new Node(3);

    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
  
    printf("Maximum difference between a node and its ancestor is : %d\n", maxDiff(root));

    return 0;
}
