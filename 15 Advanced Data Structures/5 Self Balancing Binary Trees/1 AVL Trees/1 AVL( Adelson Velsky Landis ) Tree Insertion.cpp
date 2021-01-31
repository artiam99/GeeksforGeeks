#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	int height;
	Node* left;
	Node* right;
};
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->left = node->right = NULL;
    
    node->height = 1;
    
    node->data = data;
    
    return node;
}
int Height(Node* node)
{
    if(!node)  return 0;
    
    return node->height;
}
int Get_Balance(Node* node)
{
    if(!node)  return 0;
    
    return Height(node->left) - Height(node->right);
}
Node* Left_Rotate(Node* y)
{
    Node* x = y->right;
    
    y->height = 1 + max(Height(y->left) , Height(x->left));
    
    x->height = 1 + max(Height(y) , Height(x->right));
    
    y->right = x->left;
    
    x->left = y;
    
    return x;
}
Node* Right_Rotate(Node* y)
{
    Node* x = y->left;
    
    y->height = 1 + max(Height(y->right) , Height(x->right));
    
    x->height = 1 + max(Height(y) , Height(x->left));
    
    y->left = x->right;
    
    x->right = y;
    
    return x;
}
Node* Insert(Node* node, int data)
{
    if(!node)  return newNode(data);
    
    else if(node->data < data)  node->right = Insert(node->right , data);
    
    else if(node->data > data)  node->left = Insert(node->left , data);
    
    else  return node;
    
    int balance = Get_Balance(node);
    
    if(balance > 1 && data < node->left->data)
    {
        node = Right_Rotate(node);
    }
    
    else if(balance > 1 && data > node->left->data)
    {
        node->left = Left_Rotate(node->left);
        
        node = Right_Rotate(node);
    }
    
    else if(balance < -1 && data > node->right->data)
    {
        node = Left_Rotate(node);
    }
    
    else if(balance < -1 && data < node->right->data)
    {
        node->right = Right_Rotate(node->right);
        
        node = Left_Rotate(node);
    }
    
    node->height = 1 + max(Height(node->left) , Height(node->right));
    
    return node;
}
void Inorder(Node* root)
{
	if(!root) return;
	
	Inorder(root->left);
	
	cout << root->data << " ";
	
	Inorder(root->right);
}
signed main()
{
	Node* root = NULL;
	
	root = Insert(root , 5);
	root = Insert(root , 1);
	root = Insert(root , 4);
	
	Inorder(root);
	cout << endl;
	
	return 0;
}
