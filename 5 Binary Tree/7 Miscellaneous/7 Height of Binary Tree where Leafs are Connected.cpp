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
int maxDepth(Node* root)
{
	if(!root)
	return 0;
	
	if(root->left && root->left->right == root)
	return 1;
	
	return max(maxDepth(root->left),maxDepth(root->right))+1;
}
signed main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    
    Node *L1 = root->left->left->left;
    Node *L2 = root->left->right;
    Node *L3 = root->right;

    L1->right = L2, L2->right = L3, L3->right = L1; 

    L3->left = L2, L2->left = L1, L1->left = L3; 

    cout<<"Height of tree is "<<maxDepth(root); 

    return 0;
}
