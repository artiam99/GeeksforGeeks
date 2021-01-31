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
void preorder(Node* root)
{
	if(!root)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Node* construct(vector<int> &a,int l,int r)
{
	if(l>r)
	return NULL;
	
	int m=l+(r-l)/2;
	
	Node* root=new Node(a[m]);
	
	root->left=construct(a,l,m-1);
	root->right=construct(a,m+1,r);
	
	return root;
}
signed main()
{
	vector<int> a={1,2,3,4,5,6,7};
	int n=a.size();
	
	Node* root=construct(a,0,n-1);
	
	preorder(root);
	
	return 0;
}
