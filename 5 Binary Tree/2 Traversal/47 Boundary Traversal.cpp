#include<bits/stdc++.h>
using namespace std;
#define int uint64_t
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
void preorder(Node* root,vector<pair<int,int>> &a)
{
	if(!root)
	return;
	
	if(!root->left&&!root->right)
	a.push_back({root->data,root->count});
	
	preorder(root->left,a);
	preorder(root->right,a);
}
void BoundaryTraversal(Node* root)
{
	vector<pair<int,int>> a;
	
	a.push_back({root->data,root->count});
	
	Node* curr=root->left;

	while(curr)
	{
		if(curr->left||curr->right)
		a.push_back({curr->data,curr->count});
		
		if(curr->left)
		curr=curr->left;
		
		else if(curr->right)
		curr=curr->right;
		
		else
		curr=NULL;
	}
	
	if(!(!root->left&&!root->right))// if root is not leafnode
	preorder(root,a);
	
	curr=root->right;
	
	stack<pair<int,int>> s;

	while(curr)
	{
		if(curr->left||curr->right)
		s.push({curr->data,curr->count});
		
		if(curr->right)
		curr=curr->right;
		
		else if(curr->left)
		curr=curr->left;
		
		else
		curr=NULL;
	}
	
	while(s.size())
	{
		a.push_back(s.top());
		s.pop();
	}
	
	for(auto i:a)
	cout<<i.first<<"("<<i.second<<") ";
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	BoundaryTraversal(root);
	return 0;
}
