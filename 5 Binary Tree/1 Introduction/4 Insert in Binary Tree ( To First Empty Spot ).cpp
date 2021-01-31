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
	Node* temp=new Node(x);
	if(!(*root))
	{
		*root=temp;
		return;
	}
	queue<Node*> q;
	q.push(*root);
	while(q.size())
	{
		if(!q.front()->left)
		{
			q.front()->left=temp;
			return;
		}
		else if(!q.front()->right)
		{
			q.front()->right=temp;
			return;
		}
		else
		{
			q.push(q.front()->left);
			q.push(q.front()->right);
		}
		q.pop();
	}
}
void BFT(Node* root)
{
	queue<Node*> q;
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
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	cout<<"Breadth Fisrt Traversal : ";BFT(root);cout<<endl;
	return 0;
}
