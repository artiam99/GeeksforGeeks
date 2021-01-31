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
Node* insert(Node* head,int x)
{
	Node* temp=new Node(x);
	
	if(!head)
	return temp;
	
	Node* temp1=head;
	while(temp1->right)
	temp1=temp1->right;
	
	temp->left=temp1;
	temp1->right=temp;
	
	return head;
}
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
void inorder(Node* root)
{
	if(!root)
	return;
	
	cout<<root->data<<" ";
	inorder(root->left);
	
	inorder(root->right);
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
			slow=slow->right;
			fast=fast->right;
		}
	}
	return slow;
}
Node* convert(Node* head)
{
	if(!head || !head->right)
	return head;
	
	Node* mid=findmid(head);
	
	if(mid->left)
	{
		mid->left->right=NULL;

		mid->left=convert(head);
	}
	
	mid->right->left=NULL;
	
	mid->right=convert(mid->right);
	
	return mid;
}
signed main()
{
	Node* head=NULL;
	head=insert(head,1);
	head=insert(head,2);
	head=insert(head,3);
	head=insert(head,4);
	head=insert(head,5);
	head=insert(head,6);
	head=insert(head,7);
	
	Node* root=convert(head);
	
	BFT(root);
	/*    1
	    /  \
	  2     6
	/  \  /  \
   1   3 5    7	 */
	
	return 0;
}
