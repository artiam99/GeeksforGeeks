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
bool isIsomorphic(Node *root1,Node *root2)
{
    if(!root1 && !root2)
    return true;
    
    if(root1 && root2)
    {
        if(root1->data!=root2->data)
        return false;
        
        
        return ((isIsomorphic(root1->left,root2->left)&&isIsomorphic(root1->right,root2->right))
        ||  (isIsomorphic(root1->right,root2->left)&&isIsomorphic(root1->left,root2->right)));// Nothing could be done better than this
    }
    return false;
}
signed main()
{
    Node *n1 = new Node(1); 
    n1->left        = new Node(2);
    n1->right       = new Node(3);
    n1->left->left  = new Node(4);
    n1->left->right = new Node(5);
    n1->right->left  = new Node(6);
    n1->left->right->left = new Node(7);
    n1->left->right->right = new Node(8);

    Node *n2 = new Node(1);
    n2->left         = new Node(3);
    n2->right        = new Node(2);
    n2->right->left   = new Node(4);
    n2->right->right   = new Node(5);
    n2->left->right   = new Node(6);
    n2->right->right->left = new Node(8);
    n2->right->right->right = new Node(7);

    if (isIsomorphic(n1, n2))
    cout << "Yes";
    else
    cout << "No";

    return 0;
}
