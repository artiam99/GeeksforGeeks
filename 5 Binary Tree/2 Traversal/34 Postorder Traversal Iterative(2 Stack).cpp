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
	stack<Node*> s1;
	stack<int> s2;
	s1.push(root);
	while(s1.size())
	{
		Node* temp=s1.top();
		s1.pop();
		if(temp->left)
		s1.push(temp->left);
		if(temp->right)
		s1.push(temp->right);
		s2.push(temp->data);
	}
	while(s2.size())
	{
		cout<<s2.top()<<" ";
		s2.pop();
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
