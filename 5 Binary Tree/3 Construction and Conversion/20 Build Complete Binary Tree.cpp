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
Node* insert(Node* root,int x)
{
	if(!root)
	{
		root=new Node(x);
		return root;
	}
	
	queue<Node*> q;
	
	q.push(root);
	
	while(q.size())
	{
		if(q.front()->left)
		q.push(q.front()->left);
		else
		{
			q.front()->left=new Node(x);
			return root;
		}
		if(q.front()->right)
		q.push(q.front()->right);
		else
		{
			q.front()->right=new Node(x);
			return root;
		}
		q.pop();
	}
}
void BFT(Node* root)
{
	queue<Node*> q;
	if(root)
	q.push(root);
	while(q.size())
	{
		cout<<q.front()->data<<" ";
		if(q.front()->left)
		q.push(q.front()->left);
		if(q.front()->right)
		q.push(q.front()->right);
		q.pop();
	}
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	
	for(int i=1;i<=12;i++)
	root=insert(root,i);
	
	BFT(root);
	
	return 0;
}
