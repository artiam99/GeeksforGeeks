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
void preorder(Node* root)//space optimized
{
	Node* curr=root;
	stack<Node*> s;
	while(curr||s.size())
	{
		while(curr)
		{
			cout<<curr->data<<" ";
			if(curr->right)
			s.push(curr->right);
			curr=curr->left;
		}
		if(s.size())
		{
			curr=s.top();
			s.pop();
		}
	}
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	preorder(root);
	return 0;
}
