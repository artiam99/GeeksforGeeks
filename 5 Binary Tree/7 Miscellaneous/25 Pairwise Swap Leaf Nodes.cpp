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
	Node* nextRight;
    Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void traverse(Node* root,int &c,Node* &prev)
{
    if(!root)
    return;
    if(!root->left&&!root->right)
    {
        c++;
        if(!(c&1))
        swap(root->data,prev->data);
        prev=root;
    }
    traverse(root->left,c,prev);
    traverse(root->right,c,prev);
}
void pairwiseSwap(Node *root)
{
    int c=0;
    Node* prev=NULL;
    traverse(root,c,prev);
}
signed main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout << "Inorder traversal before swap:\n";
    inorder(root);
    cout << "\n";

    pairwiseSwap(root);

    cout << "Inorder traversal after swap:\n";
    inorder(root);
    cout << "\n";

    return 0;
}
