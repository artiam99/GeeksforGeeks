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
signed main()
{
	Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    int n1=10,n2=14;
    
    Node* lca=findLCA(root,n1,n2);
    
    if(lca)
    cout<<lca->data<<endl;
    else
    cout<<"No LCA"<<endl;
    
    n1=14;n2=8;
    
    lca=findLCA(root,n1,n2);
    
    if(lca)
    cout<<lca->data<<endl;
    else
    cout<<"No LCA"<<endl;
    
    n1=10;n2=22;
    
    lca=findLCA(root,n1,n2);
    
    if(lca)
    cout<<lca->data<<endl;
    else
    cout<<"No LCA"<<endl;
    
    return 0;
}
