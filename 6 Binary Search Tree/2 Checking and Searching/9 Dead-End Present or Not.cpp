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
Node* insert(struct Node* node, int key) 
{
    if (node == NULL) return new Node(key);
    
    if (key < node->data)
    node->left = insert(node->left, key);
    
	else if (key > node->data)
    node->right = insert(node->right, key);

    return node; 
}
bool isDeadEnd(Node *root,int l=INT_MIN,int r=INT_MAX)
{
    if(!root)
    return false;
    
    if(l==r || r==1)
    return true;
    
    return (isDeadEnd(root->left,l,root->data-1)||isDeadEnd(root->right,root->data+1,r));
}
signed main()
{
    /*   8 
       /   \ 
      5    11 
     /  \ 
    2    7 
     \ 
      3 
       \ 
        4  */
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    
    if (isDeadEnd(root))
    cout << "Yes " << endl;
    else
    cout << "No " << endl;
    return 0;
}
