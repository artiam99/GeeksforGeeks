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
bool printAncestors(struct Node *root, int x)
{
    if(!root)
    return false;
    
    if(root->data==x)
    return true;
    if(printAncestors(root->left,x)||printAncestors(root->right,x))
    {
        cout<<root->data<<" ";
        return true;
    }
    return false;
}
signed main()
{ 
	Node *root = new Node(1);
	root->left        = new Node(2);
	root->right       = new Node(3);
	root->left->left  = new Node(4);
	root->left->right = new Node(5);
	root->left->left->left  = new Node(7);
  
    printAncestors(root, 7);
    
    return 0;
}
