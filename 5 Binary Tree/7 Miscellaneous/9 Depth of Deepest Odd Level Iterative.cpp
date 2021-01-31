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
int deepestOddLevelDepth(Node* root)
{
	int mx=0;
	
	queue<Node*> q;
	if(root)
	q.push(root);
	
	while(q.size())
	{
		int size=q.size();
		while(size--)
		{
			if(q.front()->left)
			q.push(q.front()->left);
			if(q.front()->right)
			q.push(q.front()->right);
			q.pop();
		}
		mx++;
	}
	if(mx & 1)
	return mx;
	return mx-1;
}
signed main()
{
    Node *root  = new Node(10);
    root->left  = new Node(28);
    root->right = new Node(13);

    root->right->left   = new Node(14);
    root->right->right  = new Node(15);

    root->right->right->left  = new Node(23);
    root->right->right->right = new Node(24);


    cout << deepestOddLevelDepth(root) << endl;

    return 0;
}
