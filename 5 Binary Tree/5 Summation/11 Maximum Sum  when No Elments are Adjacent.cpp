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
pair<int,int> traverse(Node* root)
{
	if(!root)
	return {0,0};
	
	pair<int,int> p1=traverse(root->left);
	pair<int,int> p2=traverse(root->right);
	
	return { root->data + p1.second + p2.second , max( p1.first , p1.second ) + max( p2.first , p2.second ) };
}
int getMaxSum(Node* root)
{
	pair<int,int> p=traverse(root);
	return max(p.first,p.second);
}
signed main()
{
	Node* root = new Node(1); 
    root->left = new Node(7); 
    root->right = new Node(3); 
    root->right->left = new Node(4); 
    root->right->right = new Node(5); 
    root->left->left = new Node(3); 
  
    cout<<getMaxSum(root)<<endl; 
    return 0; 
}
