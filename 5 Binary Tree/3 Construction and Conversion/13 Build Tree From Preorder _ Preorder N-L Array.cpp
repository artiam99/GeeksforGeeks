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
Node* buildTree(int pre[],char preNL[], int n,int &ind)
{
	if(ind==n)
	return NULL;
	
	Node* root=new Node(pre[ind]);
    
	if(preNL[ind++]=='L')
    return root;
    
    root->left=buildTree(pre,preNL,n,ind);
    root->right=buildTree(pre,preNL,n,ind);
    
    return root;
}
signed main()
{
	int pre[]={10,30,20,5,15};
	char preNL[]={'N','N','L','L','L'};
	
	int n=sizeof(pre)/sizeof(int);
	
	int ind=0;
	Node* root=buildTree(pre,preNL,n,ind);
	
	for(int i=0;i<n;i++)
	cout<<pre[i]<<" ";cout<<endl;
	preorder(root);cout<<endl<<endl;
	
	
	return 0;
}
