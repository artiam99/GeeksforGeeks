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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* constructuntill(int pre[],int n,int &i,int l,int r)
{
	if(i==n || pre[i]<l || pre[i]>r)
	return NULL;
	
	Node* root=new Node(pre[i++]);
	
	root->left=constructuntill(pre,n,i,l,root->data-1);
	root->right=constructuntill(pre,n,i,root->data+1,r);
	
	return root;
}
Node* construct(int pre[],int n)
{
	int i=0;
	return constructuntill(pre,n,i,intmin,intmax);
}
signed main()
{
	int pre[]={10,5,1,7,40,50};
	int n=sizeof(pre)/sizeof(int);
	
	Node* root=construct(pre,n);
	inorder(root);
	
	return 0;
}
