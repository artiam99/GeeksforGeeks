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
Node* findmid(Node* head)
{
	Node* slow=head;
	Node* fast=head->right;
	
	while(fast)
	{
		fast=fast->right;
		if(fast)
		{
			fast=fast->right;
			slow=slow->right;
		}
	}
	return slow;
}
Node* DLLtoBalanced(Node* head)
{
	if(!head || !head->right)
	return head;
	
	Node* mid=findmid(head);
	
	if(mid->left)
	{
		mid->left->right=NULL;
		mid->left=DLLtoBalanced(head);
	}
	
	mid->right->left=NULL;
	mid->right=DLLtoBalanced(mid->right);
}
Node* mergeDLL(Node* head1,Node* head2)
{
	if(!head1)
	return head2;
	
	if(!head2)
	return head1;
	
	Node* head;
	
	if(head1->data < head2->data)
	{
		head=head1;
		head->right=mergeDLL(head1->right,head2);
		if(head->right)
		head->right->left=head;
	}
	else
	{
		head=head2;
		head->right=mergeDLL(head1,head2->right);
		if(head->right)
		head->right->left=head;
	}
	return head;
}
void BTtoDLL(Node* root,Node* &prev,Node* &head)
{
	if(!root)
	return;
	
	BTtoDLL(root->left,prev,head);
	
	if(!head)
	head=root;
	
	if(prev)
	prev->right=root;
	root->left=prev;
	
	prev=root;
	
	BTtoDLL(root->right,prev,head);
	
}
Node* merge(Node* root1,Node* root2)
{
	Node* head1=NULL,*head2=NULL;
	Node* prev=NULL;
	
	BTtoDLL(root1,prev,head1);
	prev=NULL;
	BTtoDLL(root2,prev,head2);
	
	Node* head=mergeDLL(head1,head2);
	
	return DLLtoBalanced(head);
}
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
signed main()
{
	/*
        100  
        / \  
       50 300  
      / \  
    20  70    */
    
    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    /*
         80  
        / \  
      40  120  */
    
    Node *root2 = new Node(80);
    root2->left     = new Node(40);
    root2->right = new Node(120);
	
	Node* root=merge(root1,root2);
	
	inorder(root);
	
	return 0;
}
