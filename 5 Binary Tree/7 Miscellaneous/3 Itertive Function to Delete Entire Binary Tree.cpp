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
Node* deleteTree(Node* root)
{
	queue<Node*> q;
	
	if(root)
	q.push(root);
	
	while(q.size())
	{
		if(q.front()->left)
		q.push(q.front()->left);
		
		if(q.front()->right)
		q.push(q.front()->right);
		
		delete q.front();
		
		q.pop();
	}
	return NULL;
}
signed main()
{
    Node *root =  new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    root=deleteTree(root);

    return 0;
}
