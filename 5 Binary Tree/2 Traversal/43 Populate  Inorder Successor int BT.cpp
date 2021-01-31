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
	Node* next;
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
void populate(Node* root)
{
	static Node* next=NULL;
	
	if(!root)
	return;
	
	populate(root->right);
	
	root->next=next;
	
	next=root;
	
	populate(root->left);
	
}
void traverse(Node* root)
{
	if(!root)
	{
		cout<<endl;
		return;
	}
	cout<<root->data<<" ";
	traverse(root->next);
}
void inorder(Node* root)
{
	while(root->left)
	root=root->left;
	traverse(root);
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(10,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(11,&root);
	populate(root);
	inorder(root);
	return 0;
}
