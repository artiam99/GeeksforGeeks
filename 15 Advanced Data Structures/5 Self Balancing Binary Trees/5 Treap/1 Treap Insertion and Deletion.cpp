#include <bits/stdc++.h> 
using namespace std;
struct TreapNode 
{ 
	int key , priority;
	 
	TreapNode *left , *right; 
}; 

TreapNode *rightRotate(TreapNode *y) 
{ 
	TreapNode *x = y->left , *T2 = x->right; 

	x->right = y;
	
	y->left = T2; 

	return x; 
} 
 
TreapNode *leftRotate(TreapNode *x) 
{ 
	TreapNode *y = x->right , *T2 = y->left; 

	y->left = x;
	
	x->right = T2; 
 
	return y; 
} 

TreapNode* newNode(int key) 
{ 
	TreapNode* temp = new TreapNode;
	
	temp->key = key;
	
	temp->priority = rand() % 100;
	
	temp->left = temp->right = NULL;
	
	return temp; 
} 

TreapNode* search(TreapNode* root, int key) 
{ 
	if (root == NULL || root->key == key) 
	return root; 

	if (root->key < key) 
	return search(root->right, key); 

	return search(root->left, key); 
} 

TreapNode* insert(TreapNode* root, int key) 
{ 
	if (!root) 
	return newNode(key); 

	if (key <= root->key) 
	{
		root->left = insert(root->left, key); 

		if (root->left->priority > root->priority) 
		root = rightRotate(root); 
	} 
	else
	{
		root->right = insert(root->right, key); 

		if (root->right->priority > root->priority) 
		root = leftRotate(root); 
	} 
	return root; 
} 

TreapNode* deleteNode(TreapNode* root, int key) 
{ 
	if (root == NULL) 
	return root; 

	if (key < root->key) 
	root->left = deleteNode(root->left, key); 
	
	else if (key > root->key) 
	root->right = deleteNode(root->right, key); 

	else if (root->left == NULL) 
	{ 
		TreapNode *temp = root->right; 
		
		delete(root); 
		root = temp;
	} 

	else if (root->right == NULL) 
	{ 
		TreapNode *temp = root->left; 
		
		delete(root); 
		
		root = temp;
	} 

	else if (root->left->priority < root->right->priority) 
	{ 
		root = leftRotate(root); 
		root->left = deleteNode(root->left, key); 
	} 
	else
	{ 
		root = rightRotate(root); 
		root->right = deleteNode(root->right, key); 
	} 

	return root; 
} 

void inorder(TreapNode* root) 
{ 
	if (root) 
	{ 
		inorder(root->left);
		
		cout << "key : "<< root->key << " | priority : " << root->priority << endl; 
		
		inorder(root->right); 
	} 
} 

int main() 
{ 
	srand(time(NULL)); 

	struct TreapNode *root = NULL; 
	
	root = insert(root, 50); 
	root = insert(root, 30); 
	root = insert(root, 20); 
	root = insert(root, 40); 
	root = insert(root, 70); 
	root = insert(root, 60); 
	root = insert(root, 80); 

	cout << "Inorder traversal of the given tree \n"; 
	
	inorder(root);  cout << endl << endl;

	root = deleteNode(root, 20);
	root = deleteNode(root, 30); 
	root = deleteNode(root, 50);
	
	cout << "Inorder traversal of the modified tree \n"; 
	
	inorder(root);   cout << endl << endl;

	TreapNode *res = search(root, 50); 
	
	(res == NULL)? cout << "50 Not Found ": 
	
	cout << "\n50 found"; 

	return 0; 
} 

