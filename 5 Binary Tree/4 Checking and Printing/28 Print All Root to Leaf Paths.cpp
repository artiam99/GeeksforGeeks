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
void traverse(Node* root,vector<int> &a)
{
	if(!root)
	return;
	
	a.push_back(root->data);
	
	if(!root->left&&!root->right)
	{
		for(auto i:a)
		cout<<i<<" ";
		cout<<endl;
	}
	
	traverse(root->left,a);
	
	traverse(root->right,a);
	
	a.pop_back();
}
void printPaths(Node* root)
{
	vector<int> a;
	traverse(root,a);
}
signed main()
{
	Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    printPaths(root);
    
    return 0;
}
