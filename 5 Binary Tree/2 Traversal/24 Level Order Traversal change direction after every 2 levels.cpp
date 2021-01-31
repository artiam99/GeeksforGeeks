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
void LOT2Levels(Node* root)
{
	stack<Node*> s;
	queue<Node*> q;
	bool itr=0;//  0 - left to right    and    1 - right to left
	s.push(root);
	while(q.size()||s.size())
	{
		while(s.size())
		{
			if(itr)
			{
				if(s.top()->right)
				q.push(s.top()->right);
				if(s.top()->left)
				q.push(s.top()->left);
			}
			else
			{
				if(s.top()->left)
				q.push(s.top()->left);
				if(s.top()->right)
				q.push(s.top()->right);
			}
			cout<<s.top()->data<<" ";
			s.pop();
		}
		cout<<endl;
		while(q.size())
		{
			if(itr)
			{
				if(q.front()->right)
				s.push(q.front()->right);
				if(q.front()->left)
				s.push(q.front()->left);
			}
			else
			{
				if(q.front()->left)
				s.push(q.front()->left);
				if(q.front()->right)
				s.push(q.front()->right);
			}
			cout<<q.front()->data<<" ";
			q.pop();
		}
		cout<<endl;
		itr=!itr;
	}
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
    LOT2Levels(root);
	return 0;
}
