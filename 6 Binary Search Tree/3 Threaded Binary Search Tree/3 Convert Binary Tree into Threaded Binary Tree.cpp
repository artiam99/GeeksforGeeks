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
	bool rthread;
	Node(int x)
	{
		data=x;
		left=right=NULL;
		rthread=0;
	}
};
void convert(Node* root)
{
	while(root)
	{
		if(!root->left)
		root=root->right;
		else
		{
			Node* pre=root->left;
			
			while(pre->right&&pre->right!=root)
			pre=pre->right;
			
			if(!pre->right)
			{
				pre->right=root;
				pre->rthread=1;
				root=root->left;
			}
			else
			root=root->right;
		}
	}
}
void inorder(Node* root)
{
	if(!root)
	return;
	
	while(root->left)
	root=root->left;
	
	while(root)
	{
		cout<<root->data<<" ";
		
		if(root->rthread || !root->right)
		root=root->right;
		
		else
		{
			root=root->right;
			
			while(root->left)
			root=root->left;
		}
	}
	cout<<endl;
}
signed main()
{
    /*   1 
        / \ 
       2   3 
      / \ / \ 
     4  5 6  7  */
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7);
    
    convert(root);
    
	inorder(root);
	
	return 0;
}
