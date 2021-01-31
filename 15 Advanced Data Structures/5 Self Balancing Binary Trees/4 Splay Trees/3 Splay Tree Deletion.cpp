#include<bits/stdc++.h>
using namespace std;
struct node 
{ 
	int key; 
	
	struct node *left, *right; 
}; 
struct node* newNode(int key) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	
	node->key = key; 
	
	node->left = node->right = NULL; 
	
	return (node); 
} 

struct node *rightRotate(struct node *x) 
{ 
	struct node *y = x->left; 
	
	x->left = y->right; 
	
	y->right = x; 
	
	return y; 
} 

struct node *leftRotate(struct node *x) 
{ 
	struct node *y = x->right; 
	
	x->right = y->left; 
	
	y->left = x; 
	
	return y; 
} 
 
struct node *splay(struct node *root, int key) 
{ 
	if (root == NULL || root->key == key) 
	return root; 

	if (root->key > key) 
	{ 
		if (root->left == NULL) return root; 

		if (root->left->key > key) 
		{ 
			root->left->left = splay(root->left->left, key); 

			root = rightRotate(root); 
		} 
		else if (root->left->key < key)
		{
			root->left->right = splay(root->left->right, key);
			
			if (root->left->right != NULL) 
			root->left = leftRotate(root->left); 
		}
		
		return (root->left == NULL)? root: rightRotate(root); 
	} 
	else
	{
		if (root->right == NULL) return root; 

		if (root->right->key > key) 
		{ 
			root->right->left = splay(root->right->left, key); 

			if (root->right->left != NULL) 
			root->right = rightRotate(root->right); 
		} 
		else if (root->right->key < key)
		{
			root->right->right = splay(root->right->right, key); 
			
			root = leftRotate(root); 
		}
		
		return (root->right == NULL)? root: leftRotate(root); 
	} 
} 

struct node* delete_key(struct node *root, int key)
{
	struct node *temp; 
	
	if (!root)
	return NULL; 
	 
	root = splay(root, key);
	
	if (key != root->key)
	return root;
	
	if (!root->left) 
	{
		temp = root; 
		
		root = root->right; 
	} 
	
	else
	{ 
		temp = root; 

		root = splay(root->left, key); 
		
		root->right = temp->right;
	}
	
	free(temp);
	
	return root; 
}

void preOrder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		printf("%d ", root->key); 
		
		preOrder(root->left); 
		
		preOrder(root->right); 
	} 
}

int main()
{	
	struct node *root = newNode(6); 
	
	root->left = newNode(1); 
	
	root->right = newNode(9); 
	
	root->left->right = newNode(4); 
	
	root->left->right->left = newNode(2); 
	
	root->right->left = newNode(7); 

	int key = 4;

	root = delete_key(root, key);
	
	printf("Preorder traversal of the modified Splay tree is \n");
	
	preOrder(root);
	
	return 0; 
}
