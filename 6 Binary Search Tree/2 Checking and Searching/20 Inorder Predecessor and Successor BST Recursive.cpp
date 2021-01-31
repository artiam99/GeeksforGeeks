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
Node* insert(Node* node, int key)
{
    if (node == NULL)
	return new Node(key);
	
    if (key < node->data)
    node->left  = insert(node->left, key);
    else
    node->right = insert(node->right, key);
    
    return node;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
	if(!root)
	return;
	
	if(root->data ==key)
	{
		if(root->left)
		{
			Node* curr=root->left;
			while(curr->right)
			curr=curr->right;
			pre=curr;
		}
		if(root->right)
		{
			Node* curr=root->right;
			while(curr->left)
			curr=curr->left;
			suc=curr;
		}
	}
	else if(root->data<key)
	{
		pre=root;
		findPreSuc(root->right,pre,suc,key);
	}
	else
	{
		suc=root;
		findPreSuc(root->left,pre,suc,key);
	}
}
signed main()
{
    int key = 65;
   /*
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    Node* pre = NULL, *suc = NULL;

    findPreSuc(root, pre, suc, key);
    
	if (pre != NULL)
    cout << "Predecessor is " << pre->data << endl;
    else
    cout << "No Predecessor"; 
  
    if (suc != NULL)
    cout << "Successor is " << suc->data;
    else
    cout << "No Successor";
    
    return 0;
}
