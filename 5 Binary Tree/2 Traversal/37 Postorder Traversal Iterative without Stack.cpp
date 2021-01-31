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
void postorder(Node* root)
{
	unordered_map<Node*,Node*> parent;
	while(root)
	{
		if(root->left&&!parent[root->left])
		{
			parent[root->left]=root;
			root=root->left;
		}
		else if(root->right&&!parent[root->right])
		{
			parent[root->right]=root;
			root=root->right;
		}
		else
		{
			cout<<root->data<<" ";
			root=parent[root];
		}
	}
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	postorder(root);
	return 0;
}
