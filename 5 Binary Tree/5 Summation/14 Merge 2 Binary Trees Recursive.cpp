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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* MergeTrees(Node* root1,Node* root2)
{
	if(!root1)
	return root2;
	
	if(!root2)
	return root1;
	
	root1->data+=root2->data;
	
	root1->left = MergeTrees(root1->left,root2->left);
	root1->right = MergeTrees(root1->right,root2->right);
	
	return root1;
}
signed main()
{
   /*
            1 
          /   \ 
         2     3 
        / \     \ 
       4   5     6 
    */
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->right = new Node(6);

    /*
           4 
         /   \ 
        1     7 
       /     /  \ 
      3     2    6   */
    Node *root2 = new Node(4);
    root2->left = new Node(1);
    root2->right = new Node(7);
    root2->left->left = new Node(3);
    root2->right->left = new Node(2);
    root2->right->right = new Node(6);

    Node *root3 = MergeTrees(root1, root2);
    
    printf("The Merged Binary Tree is:\n");
    
	inorder(root3);
    
	return 0;
}
