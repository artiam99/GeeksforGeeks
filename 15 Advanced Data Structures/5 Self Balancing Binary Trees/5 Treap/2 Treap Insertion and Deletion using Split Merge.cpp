#include <bits/stdc++.h> 
using namespace std;
struct TreapNode 
{ 
	int key , priority;
	 
	TreapNode *left , *right;
	
	TreapNode(int x) 
	{ 
		key = x;
		
		priority = rand() % 100;
		
		left = right = NULL; 
	} 
}; 

TreapNode* search(TreapNode* root, int key) 
{ 
	if (root == NULL || root->key == key) 
	return root; 

	if (root->key < key) 
	return search(root->right, key); 

	return search(root->left, key); 
}

void Split(TreapNode* root , int x , TreapNode* &l , TreapNode* &r)
{
	l = r = NULL;
	
	if(!root)  return;
	
	if(root->key < x)
	{
		Split(root->right , x , root->right , r);
		
		l = root;
	}
	
	else
	{
		Split(root->left , x , l , root->left);
		
		r = root;
	}
}

TreapNode* Merge(TreapNode* l , TreapNode* r)
{
	if(!l || !r)  return (l ? l : r);
	
	if(l->priority > r->priority)
	{
		l->right = Merge(l->right , r);
		
		return l;
	}
	
	else
	{
		r->left = Merge(l , r->left);
		
		return r;
	}
}

TreapNode* insert(TreapNode* root, int key) 
{ 
	TreapNode* l , *r;
	
	Split(root , key , l , r);
	
	return Merge(Merge(l , new TreapNode(key)) , r);
} 

TreapNode* deleteNode(TreapNode* root, int key) 
{
	TreapNode* l , *r , *m;
	
	Split(root , key , l , m);
	
	Split(m , key + 1 , m , r);
	
	if(m && m->key == key && !m->left && !m->right)
	delete m;
	
	return Merge(l , r);
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

