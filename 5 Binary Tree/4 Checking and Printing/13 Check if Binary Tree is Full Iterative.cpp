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
bool isFullTree(Node* root)
{
	queue<Node*> q;
	
	q.push(root);
	
	while(q.size())
	{
		if((q.front()->left&&!q.front()->right)||(!q.front()->left&&q.front()->right))
		return false;
		
		if(q.front()->left)
		q.push(q.front()->left);
		
		if(q.front()->right)
		q.push(q.front()->right);
		
		q.pop();
	}
	return true;
}
signed main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
   
    root->left->right = new Node(40);
    root->left->left = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
   
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    root->left->right->left = new Node(80);
    root->left->right->right = new Node(90);
    root->right->left->left = new Node(80);
    root->right->left->right = new Node(90);
    root->right->right->left = new Node(80);
    root->right->right->right = new Node(90);
   
    if (isFullTree(root))
    cout << "The Binary Tree is full\n";
    else
    cout << "The Binary Tree is not full\n";
    
    return 0; 
}
