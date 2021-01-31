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
void preorder(Node* root)
{
	if(!root)
	return;
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorderstore(Node* root,vector<int> &a)
{
	if(!root)
	return;
	
	inorderstore(root->left,a);
	a.push_back(root->data);
	inorderstore(root->right,a);
}
void preordermodify(Node* root,vector<int> &a,int &i)
{
	if(!root)
	return;
	
	root->data=a[i++];
	preordermodify(root->left,a,i);
	preordermodify(root->right,a,i);
}
void convert(Node* root)
{
	vector<int> a;
	inorderstore(root,a);
	int i=0;
	preordermodify(root,a,i);
}
signed main()
{
	   /*    4
	       /   \
	      2     6
	    /  \   /  \
	   1   3  5    7  */
   
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    
    convert(root);
    
    /*      1
          /   \
         2     5
       /  \   /  \
      3   4  6    7   */
      
    preorder(root);  
    
	
    return 0;
}
