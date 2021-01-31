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
bool check(Node* root , int index, int n)
{
    
    if(!root)
    return true;
    
    if(index>=n)
    return false;
    
    return (check(root->left , index*2+1 , n) && check(root->right , index*2+2 , n));
    
}
int CountNodes(Node* root)
{
	if(!root)
	return 0;
	
	return 1+ CountNodes(root->left) + CountNodes(root->right);
}
bool isCompleteBT(Node* root)
{
	int n=CountNodes(root);
    
    return check(root,0,n);
}
signed main()
{
    Node *root = new Node(1);
    root->left     = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    if (isCompleteBT(root))
    cout << "Complete Binary Tree";
    else
    cout << "NOT Complete Binary Tree";
  
    return 0;
}
