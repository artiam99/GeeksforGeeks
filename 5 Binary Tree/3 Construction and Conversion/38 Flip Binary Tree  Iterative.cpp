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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* flip(Node* root)
{
	Node* prev=NULL;
	Node* next=NULL;
	Node* temp=NULL;
	Node* curr=root;
	
	while(curr)
	{
		next=curr->left;
		
		curr->left=temp;
		
		temp=curr->right;
		
		curr->right=prev;
		
		prev=curr;
		curr=next;
	}
	
	return prev;
}
signed main()
{
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
	
	inorder(root);cout<<endl<<endl;
	
	root=flip(root);
	
	inorder(root);cout<<endl<<endl;
	
	cout<<endl<<endl;
	root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	inorder(root);cout<<endl<<endl;
	
	root=flip(root);
	
	inorder(root);cout<<endl<<endl;
	
	return 0;
}
