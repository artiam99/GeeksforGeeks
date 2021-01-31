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
void insert(int x,Node** root)
{
	if(!(*root))
	{
		Node* temp=new Node(x);
		*root=temp;
		return;
	}
	if(x<=(*root)->data)
	insert(x,&((*root)->left));
	else if(x>(*root)->data)
	insert(x,&((*root)->right));
}
void Nthinorder(Node* root,int n)
{
	static int count=0;
	if(!root)
	return;
	if(count<n)
	{
		Nthinorder(root->left,n);
		count++;
		
		if(count==n)
		cout<<root->data<<endl;
		
		Nthinorder(root->right,n);
	}
}
void Nthpreorder(Node* root,int n)
{
	static int count=0;
	if(!root)
	return;
	count++;
	if(count==n)
	cout<<root->data<<endl;
	if(count<n)
	{
		Nthpreorder(root->left,n);
		
		Nthpreorder(root->right,n);
	}
}
void Nthpostorder(Node* root,int n)
{
	static int count=0;
	if(!root)
	return;
	if(count<n)
	{
		Nthpostorder(root->left,n);
		
		Nthpostorder(root->right,n);
		
		count++;
		
		if(count==n)
		cout<<root->data<<endl;
	}
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	Nthinorder(root,4);
	Nthpreorder(root,4);
	Nthpostorder(root,4);
	return 0;
}
