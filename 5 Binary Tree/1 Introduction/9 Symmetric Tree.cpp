#include<bits/stdc++.h>
using namespace std;
#define int long long
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
bool issym(Node* a,Node* b)
{
    if(!a&&!b)
    return true;
    if(a&&b&&(a->data==b->data))
    return (issym(a->left,b->right)&&issym(a->right,b->left));
    return false;
}
bool isSymmetric(struct Node* root)
{
	if(!root)
	return true;
	issym(root->left,root->right);
}
signed main()
{
	Node *root        = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(2); 
    root->left->left  = new Node(3); 
    root->left->right = new Node(4); 
    root->right->left  = new Node(4); 
    root->right->right = new Node(3);
    if(isSymmetric(root))
        cout << "tree is Symmetric"; 
    else
        cout << "\ntree is not Symmetric"; 
	return 0;
}
