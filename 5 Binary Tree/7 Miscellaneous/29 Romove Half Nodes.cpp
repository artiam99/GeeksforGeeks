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
Node *RemoveHalfNodes(Node *root)
{
   if(!root)
   return NULL;
   
   if(!root->left&&!root->right)
   return root;
   
   if(!root->left||!root->right)
   {
       Node* temp;
       
       if(root->left) temp=root->left;
       
       else if(root->right) temp=root->right;
       
       delete root;
       
       return RemoveHalfNodes(temp);
   }
   root->left=RemoveHalfNodes(root->left);
   root->right=RemoveHalfNodes(root->right);
   return root;
}
signed main()
{
    Node*NewRoot=NULL;
    
    Node *root = new Node(2);
    root->left        = new Node(7);
    root->right       = new Node(5);
    root->left->right = new Node(6);
    root->left->right->left=new Node(1);
    root->left->right->right=new Node(11);
    root->right->right=new Node(9);
    root->right->right->left=new Node(4);

    printf("Inorder traversal of given tree \n");
    inorder(root);

    NewRoot = RemoveHalfNodes(root);

    printf("\nInorder traversal of the modified tree \n");
    inorder(NewRoot);
    
    return 0;
}
