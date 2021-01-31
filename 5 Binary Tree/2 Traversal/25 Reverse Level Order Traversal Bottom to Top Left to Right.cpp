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
void ReverseLOT(Node* root)
{
	stack<int> s;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(q.size()!=1)
	{
		if(!q.front())
		{
			s.push(-1);
			q.pop();
			q.push(NULL);
			continue;
		}
		s.push(q.front()->data);
		if(q.front()->right)
		q.push(q.front()->right);
		if(q.front()->left)
		q.push(q.front()->left);
		q.pop();
	}
	while(s.size())
	{
		if(s.top()!=-1)
		cout<<s.top()<<" ";
		else
		cout<<endl;
		s.pop();
	}
	cout<<endl;
}
signed main()
{
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->left->left->left = new Node(8); 
    root->left->left->right = new Node(9); 
    root->left->right->left = new Node(3); 
    root->left->right->right = new Node(1); 
    root->right->left->left = new Node(4); 
    root->right->left->right = new Node(2); 
    root->right->right->left = new Node(7); 
    root->right->right->right = new Node(2); 
    root->left->right->left->left = new Node(16); 
    root->left->right->left->right = new Node(17); 
    root->right->left->right->left = new Node(18); 
    root->right->right->left->right = new Node(19); 
    ReverseLOT(root);
	return 0;
}
