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
int height(Node* root,int h=0)
{
	if(!root)
	return h;
	return max(height(root->left,h+1),height(root->right,h+1));
}
void go_down(Node* root,int i,bool itr)
{
	if(!root)
	return;
	if(i==1)
	cout<<root->data<<" ";
	if(itr)
	{
		go_down(root->left,i-1,itr);
		go_down(root->right,i-1,itr);
	}
	else
	{
		go_down(root->right,i-1,itr);
		go_down(root->left,i-1,itr);
	}
}
void SpiralBFT(Node* root)
{
	int h=height(root);
	bool itr=0;
	for(int i=1;i<=h;i++)
	{
		go_down(root,i,itr);
		itr=!itr;
	}
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	cout<<"Breadth Fisrt Traversal : ";SpiralBFT(root);
	return 0;
}
