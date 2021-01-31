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
Node* construct(int pre[],int prem[],int &ind,int l,int r,int n)
{
    if(l>r)
    return NULL;
    
    Node* root=(Node*)malloc(sizeof(Node));
    root->data=pre[ind++];root->left=root->right=NULL;
    
    if(l==r||ind==n)
    return root;
    
    int i;
    
    for(i=l;i<=r;i++)
    if(pre[ind]==prem[i])
    break;
    
    root->left=construct(pre,prem,ind,i,r,n);
    root->right=construct(pre,prem,ind,l+1,i-1,n);
    return root;
}
Node* buildTree(int pre[], int prem[], int n)
{
    if(!n)
    return 0;
   
    int ind=0;
    return construct(pre,prem,ind,0,n-1,n);
}
signed main()
{
	int pre[]={1, 2, 4, 8, 9, 5, 3, 6, 7};
	int post[]={8, 9, 4, 5, 2, 6, 7, 3, 1};
	
	int n=sizeof(pre)/sizeof(int);
	
	Node* root=buildTree(pre,post,n);
	
	for(int i=0;i<n;i++)
	cout<<pre[i]<<" ";cout<<endl;
	preorder(root);cout<<endl<<endl;

	return 0;
}
