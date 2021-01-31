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
bool isCompleteBT(Node* root)
{
	bool nullchild=0;
	
	queue<Node*> q;
	
	if(root)
	q.push(root);
	
	while(q.size())
	{
		if(q.front()->left)
		{
			if(nullchild)
			return false;
			q.push(q.front()->left);
		}
		else
		nullchild=1;
		
		if(q.front()->right)
		{
			if(nullchild)
			return false;
			q.push(q.front()->right);
		}
		else
		nullchild=1;
		
		q.pop();
	}
	return true;
}
signed main()
{
    Node *root = new Node(1);
    root->left     = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    if (isCompleteBT(root))
    cout << "Complete Binary Tree";
    else
    cout << "NOT Complete Binary Tree";
  
    return 0;
}
