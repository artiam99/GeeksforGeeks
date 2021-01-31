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
int sumOfNodesAtMaxDepth(Node* root)
{
	int sum=0;
	
	queue<Node*> q;
	if(root)
	q.push(root);
	
	while(q.size())
	{
		int size=q.size();
		sum=0;
		while(size--)
		{
			sum+=q.front()->data;
			if(q.front()->left)
			q.push(q.front()->left);
			if(q.front()->right)
			q.push(q.front()->right);
			q.pop();
		}
	}
	return sum;
}
signed main()
{
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    
	cout<<sumOfNodesAtMaxDepth(root);

    return 0; 
}
