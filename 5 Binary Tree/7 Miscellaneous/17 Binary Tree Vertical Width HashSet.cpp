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
void traverse(Node* root,unordered_set<int> &s,int v)
{
	if(!root)
	return;
	s.insert(v);
	traverse(root->left,s,v-1);
	traverse(root->right,s,v+1);
}
int verticalWidth(Node* root)
{
	unordered_set<int> s;
	traverse(root,s,0);
	return s.size();
}
signed main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
	  
    cout << verticalWidth(root) << "\n";
    
    return 0;
}
