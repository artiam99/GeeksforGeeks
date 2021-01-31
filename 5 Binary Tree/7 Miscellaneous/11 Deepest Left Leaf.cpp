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
Node* getDeepestLeftLeafNode(Node* root)
{
	Node* leftLeaf=NULL;
	queue<Node*> q;
	if(root)
	q.push(root);
	
	while(q.size())
	{
		if(q.front()->left)
		{
			if(!q.front()->left->left&&!q.front()->left->right)
			leftLeaf=q.front()->left;
			q.push(q.front()->left);
		}
		if(q.front()->right)
		q.push(q.front()->right);
		q.pop();
	}
	return leftLeaf;
}
signed main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->right->right->right = new Node(10);
    
    Node* result = getDeepestLeftLeafNode(root);
    if (result)
    cout << "Deepest Left Leaf Node :: "<< result->data << endl;
    else
    cout << "No result, left leaf not found\n"; 
    return 0;
}
