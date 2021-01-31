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
	int count;
	Node(int x)
	{
		data=x;
		left=right=NULL;
		count=1;
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
	if(x<(*root)->data)
	insert(x,&((*root)->left));
	else if(x>(*root)->data)
	insert(x,&((*root)->right));
	else
	(*root)->count++;
}
void preorder(Node* root,int d,vector<vector<pair<int,int>>> &dia)
{
	if(!root)
	return;
	
	if(d==dia.size())
	dia.push_back(vector<pair<int,int>>());
	
	dia[d].push_back({root->data,root->count});
	
	preorder(root->left,d+1,dia);
	
	preorder(root->right,d,dia);
}
void Diagonaltraversal(Node* root)
{
	vector<vector<pair<int,int>>> dia;
	preorder(root,0,dia);// Preorder maintians the horizontal distance (left child befor right child)
	for(auto i:dia)
	{
		for(auto j:i)
		cout<<j.first<<"("<<j.second<<") ";
	}
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	Diagonaltraversal(root);
	return 0;
}
