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
int traverse(Node* root,bool &res)
{
    if(!root)
    return 0;
    
    int l=0,r=0;
    
	if(res)
    l=traverse(root->left,res);
    
	if(res)
    r=traverse(root->right,res);
    
	if(abs(l-r)>1)
    res=0;
    
	return max(l,r)+1;
}
bool isBalanced(Node *root)
{
    bool res=1;
    traverse(root,res);
    return res;
}
signed main()
{
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->left->left->left = new Node(7); 

    if (isBalanced(root))
    cout << "Tree is balanced";
    else
    cout << "Tree is not balanced";
    return 0;
}
