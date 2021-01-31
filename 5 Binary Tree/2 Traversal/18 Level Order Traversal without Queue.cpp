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
int height(Node* root,int level=0)
{
	if(!root)
	return level;
	return max(height(root->left,level+1),height(root->right,level+1));
}
void BFTuntill(Node* root,int h)
{
	if(!root)
	return;
	if(h==1)
	cout<<root->data<<" ";
	BFTuntill(root->left,h-1);
	BFTuntill(root->right,h-1);
}
void BFT(Node* root)
{
	int h=height(root);
	for(int i=1;i<=h;i++)
	BFTuntill(root,i);
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	cout<<"Breadth Fisrt Traversal : ";BFT(root);
	return 0;
}
