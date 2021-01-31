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
void traverse(Node* root,int &mn,int &mx,int v)
{
	if(!root)
	return;
	mn=min(mn,v);
	mx=max(mx,v);
	traverse(root->left,mn,mx,v-1);
	traverse(root->right,mn,mx,v+1);
}
int getLength(Node* root)
{
	int mn=intmax,mx=intmin;
	traverse(root,mn,mx,0);
	return mx+abs(mn)+1;
}
signed main()
{
    Node* root = new Node(7); 
    root->left = new Node(6); 
    root->right = new Node(5); 
    root->left->left = new Node(4); 
    root->left->right = new Node(3); 
    root->right->left = new Node(2); 
    root->right->right = new Node(1); 
  
    cout << getLength(root) << "\n"; 
  
    return 0;
}
