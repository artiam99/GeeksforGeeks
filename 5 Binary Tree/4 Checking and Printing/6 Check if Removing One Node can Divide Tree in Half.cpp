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
int size(Node* root)
{
	static int s=0;
	if(!root)
	return 0;
	
	s++;
	size(root->left);
	size(root->right);
	return s;
}
int a=-1,b=-1;
int traverse(Node* root,bool &p,int n)
{
	if(!root)
	return 0;
	
	if(p)
	return 0;
	
	int l=traverse(root->left,p,n);
	
	if(l+l==n)
	{
		a=root->data;
		b=root->left->data;
		p=1;
	}
	
	if(p)
	return 0;
	int r=traverse(root->right,p,n);
	
	if(r+r==n)
	{
		a=root->data;
		b=root->right->data;
		p=1;
	}
	
	return l+r+1;
}
bool check(Node* root)
{
	bool p=0;
	int n=size(root);
	traverse(root,p,n);
}
signed main()
{
	Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(4);
    
    if(check(root))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl<<endl;
    cout<<a<<" "<<b<<endl;
	return 0;
}
