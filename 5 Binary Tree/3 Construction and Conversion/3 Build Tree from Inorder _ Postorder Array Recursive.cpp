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
void postorder(Node* root)
{
	if(!root)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* construct(int in[],unordered_map<int,int> &m,int post[],int l,int r,int &ind)
{   
	if(l>r)
    return NULL;
    
    
    Node* root=new Node(post[ind--]);
    int i=m[root->data];

    root->right=construct(in,m,post,i+1,r,ind);
    
    root->left=construct(in,m,post,l,i-1,ind);
    
	return root;
}
Node* buildTree(int in[],int post[], int n)
{
    unordered_map<int,int> m;
    
	for(int i=0;i<n;i++)
    m[in[i]]=i;
    
    int ind=n-1;
    
	return construct(in,m,post,0,n-1,ind);
}
signed main()
{
	int in[]={3,1,4,0,5,2};//Tihs solution cannot valid for duplicate elements ....see iterative solution
	int post[]={3,4,1,5,2,0};
	
	int n=sizeof(in)/sizeof(int);
	
	Node* root=buildTree(in,post,n);
	
	for(int i=0;i<n;i++)
	cout<<in[i]<<" ";cout<<endl;
	inorder(root);cout<<endl<<endl;
	
	for(int i=0;i<n;i++)
	cout<<post[i]<<" ";cout<<endl;
	postorder(root);
	
	return 0;
}
