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
void printLevelOrder(Node* root)
{
	queue<Node*> q;
	if(root)
	q.push(root);
	while(q.size())
	{
		int size=q.size();
		while(size--)
		{
			cout<<q.front()->data<<" ";
			if(q.front()->left)
			q.push(q.front()->left);
			if(q.front()->right)
			q.push(q.front()->right);
			q.pop();
		}
		cout<<endl;
	}
}
void sinkdown(Node* root)
{
	if(!root || (!root->left&&!root->right))
	return;
	
	if(root->left && !(root->left->data & 1))
	{
		swap(root->data,root->left->data);
		sinkdown(root->left);
	}
	else if(root->right && !(root->right->data & 1))
	{
		swap(root->data,root->right->data);
		sinkdown(root->right);
	}
}
void sinkOddNodes(Node* root)
{
	if(!root)
	return;
	
	sinkOddNodes(root->left);
	sinkOddNodes(root->right);
	
	if(root->data & 1)
	sinkdown(root);
}
signed main()
{
    Node *root = new Node(1); 
    root->left = new Node(5); 
    root->right    = new Node(8); 
    root->left->left = new Node(2); 
    root->left->right = new Node(4); 
    root->right->left = new Node(9); 
    root->right->right = new Node(10); 
  
    sinkOddNodes(root); 
  
    printf("Level order traversal of modified tree\n"); 
    printLevelOrder(root); 

    return 0;
}
