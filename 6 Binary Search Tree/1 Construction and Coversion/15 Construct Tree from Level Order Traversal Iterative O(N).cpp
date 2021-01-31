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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* construct(int lvl[],int n)
{
	if(!n)
	return NULL;
	
	queue<tuple<Node*,int,int>> q;
	
	Node* root=new Node(lvl[0]);
	
	q.push(make_tuple(root,INT_MIN,INT_MAX));
    
	int i=1;
	while(i<n)
	{
		Node* parent=get<0>(q.front());
		int left_lim=get<1>(q.front());
		int right_lim=get<2>(q.front());
		
		q.pop();
		
		if(left_lim < lvl[i] && lvl[i] < parent->data)
		{
			parent->left=new Node(lvl[i++]);
			q.push(make_tuple(parent->left,left_lim,parent->data));
		}
		if(i<n && right_lim > lvl[i] && lvl[i] > parent->data)
		{
			parent->right=new Node(lvl[i++]);
			q.push(make_tuple(parent->right,parent->data,right_lim));
		}
	}
	return root;
}
signed main()
{
	int lvl[]={7,4,12,3,6,8,1,5,10};
	int n=sizeof(lvl)/sizeof(int);
	
	Node* root=construct(lvl,n);
	inorder(root);
	
	return 0;
}
