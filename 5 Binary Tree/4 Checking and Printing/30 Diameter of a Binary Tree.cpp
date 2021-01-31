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
int traverse(Node* root,int &d)
{
	if(!root)
	return 0;
	
	int l=traverse(root->left,d);
	int r=traverse(root->right,d);
	
	d=max(d,l+r+1);
	
	return max(l,r)+1;
}
int diameter(Node* root)
{
	int d=0;
	traverse(root,d);
	return d;
}
signed main()
{
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    printf("Diameter is %d\n", diameter(root));
    
    return 0; 
}
