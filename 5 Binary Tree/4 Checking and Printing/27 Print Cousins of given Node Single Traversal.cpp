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
void printCousins(Node* root,Node* curr)
{
	if(root==curr)
	return;
	
	queue<Node*> q;
	if(root)
	q.push(root);
	
	bool found=0;
	
	while(q.size()&&!found)
	{
		int size=q.size();
		while(size--)
		{
			if(q.front()->left==curr||q.front()->right==curr)
			found=true;
			
			else
			{
				if(q.front()->left)
				q.push(q.front()->left);
				
				if(q.front()->right)
				q.push(q.front()->right);
			}
			q.pop();
		}
	}
	
	if(found)
	while(q.size())
	{
		cout<<q.front()->data<<" ";
		q.pop();
	}
	cout<<endl;
}
signed main()
{
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->right = new Node(15); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
  
    printCousins(root, root->left->right);
    
    return 0; 
}
