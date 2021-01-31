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
bool traverse(Node* root,vector<int> &a,int h=0)
{
	if(!root)
	return false;
	
	if(h==a.size())
	{
		a.push_back(root->data);
		
		if(!root->left&&!root->right)
		return true;
	}
	
	bool l=traverse(root->left,a,h+1);
	bool r=traverse(root->right,a,h+1);
	
	if(l||r)
	{
		a[h]=root->data;
		return true;
	}
	return false;
}
void LongestPath(Node* root)
{
	vector<int> a;
	
	traverse(root,a);
	
	for(auto i:a)
	cout<<i<<" ";
	cout<<endl;
}
signed main()
{
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6); 
    root->left->right->right = new Node(7); 
    root->left->left->right = new Node(8); 
    root->left->left->right->left = new Node(9); 
    
    LongestPath(root);
    
    return 0; 
}
