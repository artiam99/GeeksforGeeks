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
Node* LCA(Node* root,int a,int b)
{
	if(!root)
	return NULL;
	
	if(root->data==a||root->data==b)
	return root;
	
	Node* left=LCA(root->left,a,b);
	Node* right=LCA(root->right,a,b);
	
	if(left&&right)
	return root;
	
	return (left)?left:right;
}
bool Path(Node* root,vector<int> &a,int x)
{
	if(!root)
	return false;
	
	a.push_back(root->data);
	
	if(root->data==x)
	return true;
	
	if(Path(root->left,a,x)||Path(root->right,a,x))
	return true;
	
	a.pop_back();
	return false;
}
int printCommonPath(Node* root,int a,int b)
{
	Node* lca=LCA(root,a,b);
	vector<int> A;
	
	if(lca)
	{
		Path(root,A,lca->data);
		
		for(auto i:A)
		cout<<i<<" ";
	}
	else
	cout<<"No Common Path";
	cout<<endl;
}
signed main()
{
	Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->left->right = new Node(9);

    int n1 = 9, n2 = 6;
    printCommonPath(root, n1, n2);

    return 0;
}
