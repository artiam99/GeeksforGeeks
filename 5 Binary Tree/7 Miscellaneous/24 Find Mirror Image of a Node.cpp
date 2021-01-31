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
	Node* nextRight;
    Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
int traverse(int target,Node* left,Node* right)
{
	if(!left || !right)
	return 0;
	
	if(left->data==target)
	return right->data;
	
	if(right->data==target)
	return left->data;
	
	int l=traverse(target,left->left,right->right);
	
	if(l)
	return l;
	
	return traverse(target,left->right,right->left);
	
	
}
int findMirror(Node* root,int target)
{
	if(!root)
	return 0;
	
	if(root->data==target)
	return root->data;
	
	return traverse(target,root->left,root->right);
}
signed main()
{
    Node* root = new Node(1);
    root-> left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right    = new Node(7);
    root->right    = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left    = new Node(8);
    root->right->left->right = new Node(9);

    int target = root->left->left->data;
    
    int mirror = findMirror(root, target);

    if(mirror)
    cout << "Mirror of Node " << target  << " is Node " << mirror << endl;
    else
    cout << "Mirror of Node " << target  << " is NULL! " << endl;
    
    return 0;
}
