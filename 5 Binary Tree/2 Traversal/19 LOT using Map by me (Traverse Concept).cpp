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
	else
	insert(x,&((*root)->right));
}
void traverse(Node* root,int l,map<int,vector<int>> &m)
{
	if(!root)
	return;
	m[l].push_back(root->data);
	traverse(root->left,l+1,m);
	traverse(root->right,l+1,m);
}
void BFT(Node* root)
{
	map<int,vector<int>> m;
	traverse(root,0,m);
	for(auto i:m)
	{
		for(auto j:i.second)
		cout<<j<<" ";
	}
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	cout<<"Breadth Fisrt Traversal : ";BFT(root);
	return 0;
}
