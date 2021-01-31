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
void BFT(Node* root)
{
	queue<Node*> q;
	if(root)
	q.push(root);
	while(q.size())
	{
		cout<<q.front()->data<<" ";
		if(q.front()->left)
		q.push(q.front()->left);
		if(q.front()->right)
		q.push(q.front()->right);
		q.pop();
	}
	cout<<endl;
}
Node* construct(int a[],Node* root,int ind,int n)
{
	if(ind>=n)
	return NULL;
	
	root=new Node(a[ind]);
	root->left=construct(a,root->left,ind*2+1,n);
	root->right=construct(a,root->right,ind*2+2,n);
	return root;
}
signed main()
{
	int a[]={1,2,3,4,5,6,6,6,6};
    int n=sizeof(a)/sizeof(int);
	
	Node* root=construct(a,root,0,n);
	
	cout<<"Array: ";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";cout<<endl;
	
	cout<<"Tree : ";
	BFT(root);
	return 0; 
}
