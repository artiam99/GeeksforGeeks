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
int minDepth(Node* root)
{
	int mn=0;
	queue<Node*> q;
	if(root)
	q.push(root);
	
	while(q.size())
	{
		mn++;
		int size=q.size();
		while(size--)
		{
			if(!q.front()->left&&!q.front()->right)
			return mn;
			if(q.front()->left)
			q.push(q.front()->left);
			if(q.front()->right)
			q.push(q.front()->right);
			q.pop();
		}
	}
	return mn;
}
signed main()
{
    Node *root     = new Node(1);
    root->left     = new Node(2);
    root->right     = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout <<"The minimum depth of binary tree is : "<< minDepth(root);
    return 0;
}
