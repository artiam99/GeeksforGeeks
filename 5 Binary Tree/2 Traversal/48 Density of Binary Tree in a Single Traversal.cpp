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
int preorder(Node* root,int &size)
{
	if(!root)
	return 0;
	
	cout<<root->data<<" ";
	
	size++;
	
	return max(preorder(root->left,size)+1,preorder(root->right,size)+1);
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	int size=0;
	int height=preorder(root,size);cout<<endl;
	cout<<"Density : "<<(float)size/(float)height;
	return 0;
}
