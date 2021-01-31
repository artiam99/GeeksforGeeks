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
Node* LCA(Node* root,int a,int b)
{
	if(!root)
	return NULL;
	
	if(root->data==a||root->data==b)
	return root;
	
	Node* left=LCA(root->left,a,b);
	Node* right=LCA(root->right,a,b);
	
	if(left&&right)
	return root;
	
	return (left)?left:right;
}
int distance(Node* root,int x)
{
	if(!root)
	return 0;
	
	if(root->data==x)
	return 1;
	
	int l=distance(root->left,x);
	if(l)
	return l+1;
	
	int r=distance(root->right,x);
	if(r)
	return r+1;
	
	return 0;
}
int findDistance(Node* root,int a,int b)
{
	Node* lca=LCA(root,a,b);
	return distance(lca,a)+distance(lca,b)-2;
}
signed main()
{
	Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5)<<endl;
    cout << "nDist(4, 6) = " << findDistance(root, 4, 6)<<endl;
    cout << "nDist(3, 4) = " << findDistance(root, 3, 4)<<endl;
    cout << "nDist(2, 4) = " << findDistance(root, 2, 4)<<endl;
    cout << "nDist(8, 5) = " << findDistance(root, 8, 5)<<endl;
    
    return 0;
}
