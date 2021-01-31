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
	stack<pair<Node*,int>> s;
	s.push({root,0});
	while(s.size())
	{
		root=s.top().first;
		int p=s.top().second;
		s.pop();
		if(p==0)
		{
			s.push({root,1});
			if(root->left)
			s.push({root->left,0});
		}
		else if(p==1)
		{
			s.push({root,2});
			if(root->right)
			s.push({root->right,0});
		}
		else
		cout<<root->data<<" ";
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
