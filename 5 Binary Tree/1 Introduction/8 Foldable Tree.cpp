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
bool ismirror(Node* a,Node* b)
{
	if(!a&&!b)
	return true;
	if(a&&b)
	return (ismirror(a->left,b->right)&&ismirror(a->right,b->left));
	return false;
}
bool isFoldable(Node* root)
{
	if(!root)  return true;
	return ismirror(root->left,root->right);
}
signed main()
{
	Node* root=new Node(1); 
    root->left=new Node(2); 
    root->right=new Node(3); 
    root->right->left=new Node(4); 
    root->left->right=new Node(5);
    if(isFoldable(root))
        cout << "tree is foldable"; 
    else
        cout << "\ntree is not foldable"; 
	return 0;
}
