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
Node *createNode(int x)
{
    Node *p = new Node(x);
    return p;
}
void insertNode(Node *root, int x)
{
    Node *p = root, *q = NULL;

    while (p != NULL)
    {
        q = p;
        if (p -> data < x)
        p = p -> right;
        else
        p = p -> left;
    }
    if (q == NULL)
    p = createNode(x);
    else
    {
        if (q -> data < x)
        q -> right = createNode(x);
        else
        q -> left = createNode(x);
    }
}
Node* findlca(Node* root,int a,int b)
{
	Node* x=root,*y=root;
	Node* lca=NULL;
	while(x && y &&(x->data!= a || y->data!=b))
	{
		if(x==y)
		lca=x;
		
		if(x->data<a)
		x=x->right;
		else if(x->data>a)
		x=x->left;
		
		if(y->data<b)
		y=y->right;
		else if(y->data>b)
		y=y->left;
	}
	if(x && y)
	return lca;
	return NULL;
}
int maximumElement(Node* root,int a,int b)
{
	Node* lca=findlca(root,a,b);
	if(!lca)
	return -1;
	
	int x;
	
	if(lca->data!=a && lca->data!=b)
	x=max(a,b);
	else
	{
		if(lca->data==a)
		x=b;
		else
		x=a;
	}
	int mx=INT_MIN;
	
	while(lca->data!=x)
	{
		mx=max(mx,lca->data);
		if(lca->data<x)
		lca=lca->right;
		else
		lca=lca->left;
	}
	return mx;
}
signed main()
{
    int arr[] = { 18, 36, 9, 6, 12, 10, 1, 8 };
    int a = 1, b = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *root = createNode(arr[0]);

    for (int i = 1; i < n; i++)
    insertNode(root, arr[i]);

    cout << maximumElement(root, a, b) << endl;

    return 0;
}
