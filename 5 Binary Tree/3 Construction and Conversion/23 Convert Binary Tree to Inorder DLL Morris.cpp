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
Node* BTtoDLL(Node* root)
{
	Node* head=NULL,*prev=NULL,*curr=root,*pre;
	
	while(curr)
	{
		if(!curr->left)
		{
			if(!head)
			head=curr;
			
			if(prev)
			{
				curr->left=prev;
				prev->right=curr;
			}
			prev=curr;
			
			curr=curr->right;
		}
		else
		{
			pre=curr->left;
			while(pre->right&&pre->right!=curr)
			pre=pre->right;
			
			if(!pre->right)
			{
				pre->right=curr;
				curr=curr->left;
			}
			else
			{
				prev->right=curr;//when we are visiting a Node for second time or its left is NULL we are done with it so we can change prev's right and curr's left
				curr->left=prev;
				prev=curr;
				
				curr=curr->right;
			}
		}
	}
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
