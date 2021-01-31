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
void traverse(Node* root,int &mx,int h=1)
{
	if(!root)
	return;
	
	if(h & 1)
	mx=max(mx,h);
	traverse(root->left,mx,h+1);
	traverse(root->right,mx,h+1);
}
int deepestOddLevelDepth(Node* root)
{
	int mx=0;
	traverse(root,mx);
	return mx;
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
