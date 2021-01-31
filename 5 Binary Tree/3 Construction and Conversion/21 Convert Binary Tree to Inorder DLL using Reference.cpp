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
void print_list(Node* head)
{
	Node* tail;
	while(head)
	{
		cout<<head->data<<" ";
		tail=head;
		head=head->right;
	}
	cout<<endl;
	while(tail)
	{
		cout<<tail->data<<" ";
		tail=tail->left;
	}
	cout<<endl;
}
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void convert(Node* root,Node* &prev,Node* &head)
{
	if(!root)
	return;
	
	convert(root->left,prev,head);
	
	if(!head)
	head=root;
	
	if(prev)
	prev->right=root;
	
	root->left=prev;
	
	prev=root;
	
	convert(root->right,prev,head);
}
Node* BTtoDLL(Node* root)
{
	Node* prev=NULL,*head=NULL;
	convert(root,prev,head);
	return head;
}
signed main()
{
	Node *root = new Node(10);  
    root->left = new Node(12);  
    root->right = new Node(15);  
    root->left->left = new Node(25);  
    root->left->right = new Node(30);  
    root->right->left = new Node(36);
  
    inorder(root);cout<<endl<<endl;
  
    Node* head=BTtoDLL(root);
    
	print_list(head);
	
	return 0;
}
