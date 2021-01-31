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
void BFT(Node* root)
{
	queue<Node*> q;
	if(root)
	q.push(root);
	while(q.size())
	{
		int size=q.size();
		while(size--)
		{
			cout<<q.front()->data<<" ";
			
			if(q.front()->left)
			q.push(q.front()->left);
			
			if(q.front()->right)
			q.push(q.front()->right);
			
			q.pop();
		}
		cout<<endl;
	}
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
void DLLtoBT(Node* head)
{
	queue<Node*> q;
	
	if(head)
	{
		q.push(head);
		
		head=head->right;
		
		q.front()->left=q.front()->right=NULL;
	}
	
	while(head)
	{
		Node* parent=q.front();
		
		q.pop();
		
		Node* leftchild=head;
		
		head=head->right;
		
		q.push(leftchild);
		
		parent->left=leftchild;
		
		leftchild->left=leftchild->right=NULL;
		
		if(head)
		{
			Node* rightchild=head;
			
			head=head->right;
			
			q.push(rightchild);
			
			parent->right=rightchild;
			
			rightchild->left=rightchild->right=NULL;
		}
	}
}
Node* convert(Node* root)
{
	Node* prev=NULL;
	Node* head=NULL;
	
	inorderDLL(root,prev,head);
	
	DLLtoBT(head);
	
	return head;
}
signed main()
{
	/*      8
	     /    \
	    4      12
	  /  \     /  \
	 2    6   10  14  */
	
	Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    
    root=convert(root);
    
    /*      2 
          /   \ 
         4     6 
       /  \   /  \ 
      8   10 12   14  */
      
    BFT(root);   
	
    return 0;
}
