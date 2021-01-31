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
bool treeContinuous(Node* root)
{
	if(!root)  return true;
	
	bool l= (root->left) ? ( (abs(root->data - root->left->data) == 1 ) ? treeContinuous(root->left) : false ) : true;
	
	bool r= (root->right) ? ( ( abs(root->data - root->right->data) == 1 ) ? treeContinuous(root->right) : false ) : true;
	
	
	return (l&&r);
}
signed main()
{
	Node *root=new Node(3); 
    root->left= new Node(2); 
    root->right=new Node(4); 
    root->left->left=new Node(1); 
    root->left->right=new Node(3); 
    root->right->right=new Node(5); 
    treeContinuous(root)?  cout << "Yes" : cout << "No"; 
	return 0;
}
