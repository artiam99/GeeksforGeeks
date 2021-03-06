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
void postorder(Node* root)
{
	if(!root)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
Node* construct(int pre[],int post[],int &ind,unordered_map<int,int> &m,int l,int r,int n)
{
	if(l>r)
	return NULL;
	
	Node* root=new Node(pre[ind++]);
	
	if(l==r||ind==n)// l==r pre[ind] was last element in the range
	return root;
	
	int i=m[pre[ind]];//O(N^2) solution is faster use that... i.e. finding index of next preind value in post in the range l to r 
	
	root->left=construct(pre,post,ind,m,l,i,n);//left subtree range l to i... eg. pre 1,2,4,8,9,5,3,6,7  post 8,9,4,5,2,6,7,3,1  
	
    root->right=construct(pre,post,ind,m,i+1,r-1,n);// right sub tree range i+1 to r   ... for root = 1 left  subtree is 8,9,4,5,2  and  Right subtree is 6,7,3
	
	return root;
}
Node* buildTree(int pre[],int post[], int n)
{
    unordered_map<int,int> m;
    
	for(int i=0;i<n;i++)
    m[post[i]]=i;
    
    int ind=0;
    return construct(pre,post,ind,m,0,n-1,n);
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
	
	for(int i=0;i<n;i++)
	cout<<post[i]<<" ";cout<<endl;
	postorder(root);
	
	return 0;
}
