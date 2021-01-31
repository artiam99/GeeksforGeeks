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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* construct(int in[],unordered_map<int,int> &m,int pre[],int l,int r)
{
    static int ind=0;
    
	if(l>r)
    return NULL;
    
    
    Node* root=new Node(pre[ind++]);
    int i=m[root->data];

    root->left=construct(in,m,pre,l,i-1);
    
	root->right=construct(in,m,pre,i+1,r);
    
	return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    unordered_map<int,int> m;
    
	for(int i=0;i<n;i++)
    m[in[i]]=i;
    
	return construct(in,m,pre,0,n-1);
}
signed main()
{
	int in[]={3,1,4,0,5,2};//Tihs solution cannot valid for duplicate elements ....see iterative solution
	int pre[]={0,1,3,4,2,5};
	
	int n=sizeof(in)/sizeof(int);
	
	Node* root=buildTree(in,pre,n);
	
	for(int i=0;i<n;i++)
	cout<<in[i]<<" ";cout<<endl;
	inorder(root);cout<<endl<<endl;
	
	for(int i=0;i<n;i++)
	cout<<pre[i]<<" ";cout<<endl;
	preorder(root);
	
	return 0;
}
