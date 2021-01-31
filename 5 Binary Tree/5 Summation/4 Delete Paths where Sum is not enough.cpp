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
void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d ",root->data);
        print(root->right);
    }
}
bool pruneuntill(Node* root,int sum,int k)
{
	if(!root)
	return false;
	
	sum+=root->data;
	bool l=pruneuntill(root->left,sum,k);
	bool r=pruneuntill(root->right,sum,k);
	
	if(!l)
	root->left=NULL;
	
	if(!r)
	root->right=NULL;
	
	if(l||r)
	return true;
	
	if(sum>=k)
	return true;
	
	return false;
}
Node* prune(Node* root,int k)
{
	pruneuntill(root,0,k);
	return root;
}
signed main()
{
	int k = 45;
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(12);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->left->left->right->left = new Node(13);
    root->left->left->right->right = new Node(14);
    root->left->left->right->right->left = new Node(15);

    printf("Tree before truncation\n");
    print(root);

    root = prune(root, k);

    printf("\n\nTree after truncation\n");
    print(root);
    
    return 0; 
}
