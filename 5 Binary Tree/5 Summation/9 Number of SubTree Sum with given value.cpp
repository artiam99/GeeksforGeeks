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
int traverse(Node* root,int x,int &c)
{
	if(!root)
	return 0;
	
	int l=traverse(root->left,x,c);
	int r=traverse(root->right,x,c);
	
	if(l+r+root->data==x)
	c++;
	
	return l+r+root->data;
}
int countSubtreesWithSumXUtil(Node* root,int x)
{
	int c=0;
	traverse(root,x,c);
	return c;
}
signed main()
{
	Node* root = new Node(5);
    root->left = new Node(-10);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(8);
    root->right->left = new Node(-4);
    root->right->right = new Node(7);

    int x = 7;

    cout << "Count = "<<countSubtreesWithSumXUtil(root, x);

    return 0; 
}
