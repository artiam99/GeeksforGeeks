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
void preordermat(Node* root,vector<vector<int>> &m)
{
	if(!root)
	return;
	int i1=-1;
	int i2=-1;
	
	if(root->left)
	{
		m[root->data][root->left->data]=1;
		i1=root->left->data;
	}
	
	if(root->right)
	{
		m[root->data][root->right->data]=1;
		i2=root->right->data;
	}
	
	for(int i=0;i<m.size();i++)
	if(m[i][root->data]==1)
	{
		if(i1!=-1)
		m[i][i1]=1;
		if(i2!=-1)
		m[i][i2]=1;
	}
	
	preordermat(root->left,m);
	preordermat(root->right,m);
}
void size(Node* root,int &n)
{
	if(!root)
	return;
	n++;
	size(root->left,n);
	size(root->right,n);
}
void  Matrix(Node* root)
{
	int n=0;
	size(root,n);
	vector<vector<int>> m(n,vector<int>(n,0));
	
	preordermat(root,m);
	
	for(auto i:m)
	{
		for(auto j:i)
		cout<<j<<" ";
		cout<<endl;
	}
}
signed main()
{
	Node *root = new Node(5);  
    root->left = new Node(1);  
    root->right = new Node(2);  
    root->left->left = new Node(0);  
    root->left->right = new Node(4);  
    root->right->left = new Node(3);  
  
    Matrix(root);
	
	return 0;
}
