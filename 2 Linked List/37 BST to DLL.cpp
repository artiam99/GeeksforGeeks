#include<iostream>
using namespace std;

struct node
{
	int data;

	node *left , *right;
};

node* insert(node* root , int x)
{
	if(root == NULL)
	{
		node* temp = new node();
		
		temp->data = x;
		
		temp->left = temp->right = NULL;
		
		root = temp;
	}
	
	else if(x <= root->data)
	root->left = insert(root->left , x);
	
	else
	root->right = insert(root->right , x);
	
	return root;
}

void preorder(node* root)
{
	if(root == NULL)
	return;

	cout << root->data << " ";

	preorder(root->left);

	preorder(root->right);
}

void inorder(node* root)
{
	if(root == NULL)
	return;

	inorder(root->left);
	
	cout << root->data << " ";
	
	inorder(root->right);
}

void postorder(node* root)
{
	if(root == NULL)
	return;

	postorder(root->left);

	postorder(root->right);

	cout << root->data << " ";
}

void preorderedDLL(node* root , node** head)
{
	if(root == NULL)
	return;
	
	static node* prev = NULL;
	
	node* left;
	
	node* right;
	
	if(*head == NULL)
	{
		*head = root;
		
		left = (*head)->left;
		
		right = (*head)->right;
		
		(*head)->left = prev;
	}
	
	else
	{
		left = root->left;
	
		right = root->right;
	
		root->left = prev;
	
		prev->right = root;
	}
	
	prev = root;
	
	preorderedDLL(left , head);

	preorderedDLL(right , head);
}

void inorderedDLL(node* root , node** head)
{
	if(root == NULL)
	return;
	
	static node* prev = NULL;
	
	inorderedDLL(root->left , head);
	
	if(*head == NULL)
	*head = root;
	
	else
	{
		prev->right = root;
		
		root->left = prev;
	}
	
	prev = root;
	
	inorderedDLL(root->right , head);
}

void postorderedDLL(node* root , node** head)
{
	if(root == NULL)
	return;
	
	static node* prev = NULL;
	
	postorderedDLL(root->left , head);
	
	postorderedDLL(root->right , head);
	
	if(*head == NULL)
	*head = root;
	
	else
	{
		prev->right = root;
		
		root->left = prev;
	}
	
	root->right = NULL;
	
	prev = root;
}

void printDLL(node* head)
{
	cout << endl << endl;

	node* tail;
	
	while(head)
	{
		tail = head;
	
		cout << head->data << " ";
	
		head = head->right;
	}
	
	cout << endl;
	
	while(tail)
	{
		cout << tail->data << " ";
		
		tail = tail->left;
	}
	
	cout << endl << endl;
}

int main()
{
	cout << "Preordered" << endl << endl;

	node* root = NULL;
	
	root = insert(root , 15);
	root = insert(root , 10);
	root = insert(root , 8);
	root = insert(root , 12);
	root = insert(root , 17);
	root = insert(root , 25);
	root = insert(root , 16);
	
	preorder(root);
	
	node* head = NULL;

	preorderedDLL(root , &head);

	printDLL(head);
	
	cout << "Inordered" << endl << endl;

	root = NULL;

	root = insert(root , 15);
	root = insert(root , 10);
	root = insert(root , 8);
	root = insert(root , 12);
	root = insert(root , 17);
	root = insert(root , 25);
	root = insert(root , 16);
	
	inorder(root);
	
	head = NULL;
	
	inorderedDLL(root , &head);
	
	printDLL(head);
	
	cout << "Postordered" << endl << endl;
	
	root = NULL;
	
	root = insert(root , 15);
	root = insert(root , 10);
	root = insert(root , 8);
	root = insert(root , 12);
	root = insert(root , 17);
	root = insert(root , 25);
	root = insert(root , 16);
	
	postorder(root);
	
	head = NULL;
	
	postorderedDLL(root , &head);
	
	printDLL(head);
	
	return 0;
}

