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
void inorderDLL(Node* root,Node* &prev,Node* &head)
{
	if(!root)
	return;
	inorderDLL(root->left,prev,head);
	
	if(!head)
	head=root;
	
	if(prev)
	prev->right=root;
	root->left=prev;
	
	prev=root;
	
	inorderDLL(root->right,prev,head);
}
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
Node* DLLtoBalancedBT(Node* head)
{
	if(!head || !head->right)
	return head;
	
	Node* mid=findmid(head);
	
	if(mid->left)
	{
		mid->left->right=NULL;
		mid->left=DLLtoBalancedBT(head);
	}
	mid->right->left=NULL;
	mid->right=DLLtoBalancedBT(mid->right);
	return mid;
}
Node* convert(Node* root)
{
	Node *head=NULL,*prev=NULL;
	inorderDLL(root,prev,head);
	return DLLtoBalancedBT(head);
}
signed main()
{
	
    /*
                10 
               / 
              8 
             / 
            7 
           / 
          6 
         / 
        5   */
    
	Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    
    root=convert(root);
    
    preorder(root);
	
	return 0;
}
