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
int height(Node* root,int level=0)
{
	if(!root)
	return level;
	return max(height(root->left,level+1),height(root->right,level+1));
}
void ReverseBFTuntill(Node* root,int h)
{
	if(!root)
	return;
	if(h==1)
	cout<<root->data<<" ";
	ReverseBFTuntill(root->left,h-1);
	ReverseBFTuntill(root->right,h-1);
}
void ReverseBFT(Node* root)
{
	int h=height(root);
	for(int i=h;i>=1;i--)
	{
		ReverseBFTuntill(root,i);
	    cout<<endl;
	}
}
signed main()
{
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->left->left->left = new Node(8); 
    root->left->left->right = new Node(9); 
    root->left->right->left = new Node(3); 
    root->left->right->right = new Node(1); 
    root->right->left->left = new Node(4); 
    root->right->left->right = new Node(2); 
    root->right->right->left = new Node(7); 
    root->right->right->right = new Node(2); 
    root->left->right->left->left = new Node(16); 
    root->left->right->left->right = new Node(17); 
    root->right->left->right->left = new Node(18); 
    root->right->right->left->right = new Node(19);
	ReverseBFT(root);
	return 0;
}
