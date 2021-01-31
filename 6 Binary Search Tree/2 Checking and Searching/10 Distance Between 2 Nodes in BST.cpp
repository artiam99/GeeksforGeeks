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
Node* insert(Node* root, int key)
{
    if (!root)
    root = new Node(key);
    
    else if (root->data > key)
    root->left = insert(root->left, key);
    
    else if (root->data < key)
    root->right = insert(root->right, key);
    
    return root;
}
Node* findLCA(Node* root,int n1,int n2)
{
	Node* lca=NULL;
	
	Node* a=root,*b=root;
	
	while(a && b && (a->data!=n1 || b->data!=n2))
	{
		if(a==b)
		lca=a;
		
		if(a->data<n1)
		a=a->right;
		else if(a->data>n1)
		a=a->left;
		
		if(b->data<n2)
		b=b->right;
		else if(b->data>n2)
		b=b->left;
	}
	if(a&&b)
	return lca;
	return NULL;
}
int findDistWrapper(Node* root,int n1,int n2)
{
	Node* lca=findLCA(root,n1,n2);
	
	if(!lca)
	return 0;
	
	int c=0;
	Node* a=lca,*b=lca;
	
	while(a->data!=n1)
	{
		if(a->data<n1)
		a=a->right;
		else
		a=a->left;
		c++;
	}
	
	while(b->data!=n2)
	{
		if(b->data<n2)
		b=b->right;
		else
		b=b->left;
		c++;
	}
	
	return c;
}
signed main()
{
	Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);
    
    int a = 5, b = 55;
    
    cout << findDistWrapper(root, 5, 35);
    
    return 0;
}
