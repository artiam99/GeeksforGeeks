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
Node* traverse(Node* root,int a,int b)
{
	if(!root)
	return NULL;
	
	if(root->data==a||root->data==b)
	return root;
	
	Node* left=traverse(root->left,a,b);
	Node* right=traverse(root->right,a,b);
	
	if(left&&right)// if one in left and anothoer in right subtree
	return root;
	
	return (left)?left:right; // if both in left or right subtree
}
int findLCA(Node* root,int a,int b)
{
	return traverse(root,a,b)->data;
}
signed main()
{
	Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)<<endl;
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)<<endl;
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)<<endl;
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)<<endl;
    
    return 0;
}
