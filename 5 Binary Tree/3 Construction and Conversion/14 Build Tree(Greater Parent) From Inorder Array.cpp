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
int getmax(int a[],int *st,int al,int ar,int ql,int qr,int sti)
{
	if(al>=ql&&ar<=qr)
	return st[sti];
	if(al>qr||ar<ql)
	return -1;
	int m=al+(ar-al)/2;
	int i1=getmax(a,st,al,m,ql,qr,sti*2+1);
	int i2=getmax(a,st,m+1,ar,ql,qr,sti*2+2);
	if(i1==-1)
	return i2;
	if(i2==-1)
	return i1;
	return (a[i1]>a[i2])?i1:i2;
}
void constructuntill(int a[],int al,int ar,int *st,int sti)
{
	if(al==ar)
	{
		st[sti]=al;
		return;
	}
	int m=al+(ar-al)/2;
	constructuntill(a,al,m,st,sti*2+1);
	constructuntill(a,m+1,ar,st,sti*2+2);
	st[sti]=(a[st[sti*2+1]]>a[st[sti*2+2]])?st[sti*2+1]:st[sti*2+2];
}
int* construct(int a[],int n)
{
	int p=ceil(log2(n));
	int size=2*pow(2,p)-1;
	int *st=new int[size];
	constructuntill(a,0,n-1,st,0);
	return st;
}
Node* constree(int in[],int l,int r,int *st,int n)
{
	if(l>r)
	return NULL;
	int i=getmax(in,st,0,n-1,l,r,0);
	Node* root=new Node(in[i]);
	root->left=constree(in,l,i-1,st,n);
	root->right=constree(in,i+1,r,st,n);
	return root;
}
Node* buildTree(int in[], int n)
{
	int *st=construct(in,n);
    return constree(in,0,n-1,st,n);
}
signed main()
{
	int in[]={1,5,10,40,30,15,28,20};
	
	int n=sizeof(in)/sizeof(int);
	
	Node* root=buildTree(in,n);
	
	for(int i=0;i<n;i++)
	cout<<in[i]<<" ";cout<<endl;
	inorder(root);cout<<endl<<endl;
	
	return 0;
}
