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
void traverse(Node* root,unordered_map<int,int> &m,int &mx)
{
	if(!root)
	return;
	
	m[root->data]++;
	
	if(!root->left && !root->right)
	mx=max(mx,(int)m.size());
	
	traverse(root->left,m,mx);
	traverse(root->right,m,mx);
	
	m[root->data]--;
	
	if(m[root->data]==0)
	m.erase(root->data);
}
int largestUinquePath(Node* root)
{
	int mx=0;
	unordered_map<int,int> m;
	traverse(root,m,mx);
	return mx;
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

    cout << largestUinquePath(root) << endl;
    
    return 0;
}
