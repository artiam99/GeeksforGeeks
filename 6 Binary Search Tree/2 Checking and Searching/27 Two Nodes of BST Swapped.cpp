#include<bits/stdc++.h>
using namespace std;
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
	cout<<root->data<<' ';
	inorder(root->right);
}
void traverse(Node* root,Node* &prev,Node* &node1,Node* &node2)
{
    if(!root) return;
    
    traverse(root->left,prev,node1,node2);
    
    if(prev && prev->data>root->data)
    {
        if(!node1)
        {
        	node1=prev;
            node2=root;
        }
        else node2=root;
    }
    
    prev=root;
   
    traverse(root->right,prev,node1,node2);
}
struct Node *correctBST( struct Node* root )
{
    Node* prev=NULL,*node1=NULL,*node2=NULL;
    
    traverse(root,prev,node1,node2);
    
    swap(node1->data,node2->data);
    
    return root;
}
signed main()
{

    /*   6 
        /  \ 
       10    2 
      / \   / \ 
     1   3 7  12
     
     10 and 2 are swapped  */
  
    Node *root = new Node(6);
    root->left        = new Node(10);
    root->right       = new Node(2);
    root->left->left  = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    printf("Inorder Traversal of the original tree \n"); 
    inorder(root); 
  
    correctBST(root); 
  
    printf("\nInorder Traversal of the fixed tree \n"); 
    inorder(root); 
  
    return 0;
}
