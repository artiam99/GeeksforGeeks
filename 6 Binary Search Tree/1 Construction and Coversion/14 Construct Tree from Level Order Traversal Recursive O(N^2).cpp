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
Node* constructuntill(int lvl[],int n,int i,int l,int r)
{
	if(i==n || l>r)
	return NULL;
	
	while(i<n && (lvl[i]<l || lvl[i]>r))
	i++;
	
	if(i==n)
	return NULL;
	
	Node* root=new Node(lvl[i]);
	
	root->left=constructuntill(lvl,n,i+1,l,root->data-1);
	root->right=constructuntill(lvl,n,i+1,root->data+1,r);
	
	return root;
}
Node* construct(int lvl[],int n)
{
	int i=0;
	return constructuntill(lvl,n,i,intmin,intmax);
}
signed main()
{
	int lvl[]={7,4,12,3,6,8,1,5,10};
	int n=sizeof(lvl)/sizeof(int);
	
	Node* root=construct(lvl,n);
	inorder(root);
	
	return 0;
}
