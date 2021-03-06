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
void postorder(Node* root)
{
	if(!root)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void BTtoDLL(Node* root,Node* &head)
{
	static Node* prev=NULL;
	
	if(!root)
	return;
	
	BTtoDLL(root->left,head);
	BTtoDLL(root->right,head);
	
	if(!head)
	head=root;
	
	root->left=prev;
	
	if(prev)
	prev->right=root;
	
	
	
	prev=root;
}
signed main()
{
	Node *root = new Node(10);  
    root->left = new Node(12);  
    root->right = new Node(15);  
    root->left->left = new Node(25);  
    root->left->right = new Node(30);  
    root->right->left = new Node(36);
    
    postorder(root);cout<<endl<<endl;
    
	Node* head=NULL;
	BTtoDLL(root,head);
	root->right=NULL;
    
	print_list(head);
	
	return 0;
}
