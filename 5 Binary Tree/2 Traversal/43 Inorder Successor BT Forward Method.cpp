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
void insert(int x,Node** root)
{
	if(!(*root))
	{
		Node* temp=new Node(x);
		*root=temp;
		return;
	}
	if(x<=(*root)->data)
	insert(x,&((*root)->left));
	else if(x>(*root)->data)
	insert(x,&((*root)->right));
}
void inorder(Node* root)
{
	cout<<"Inorder Traversal : ";
	stack<Node*> st;
	Node* curr=root;
	while(curr||st.size())
	{
		while(curr)
		{
			st.push(curr);
			curr=curr->left;
		}
		cout<<st.top()->data<<" ";
		curr=st.top()->right;
		st.pop();
	}
	cout<<endl<<endl;
}
Node* findleftmost(Node* root)
{
	if(!root->left)
	return root;
	return findleftmost(root->left);
}
void inordersuccessor(Node* root,int key,Node* &next,bool &itr,Node* &x)
{
	if(!root)
	return;
	
	if(!itr)
	inordersuccessor(root->left,key,next,itr,x);
	
	if(root->data==key)
	{
		itr=1;
		
		if(root->right)
		next=findleftmost(root->right);//if key node ( x ) has right chile then inorder successor will be the leftmost node of right subtree
		
		x=root;//else find if x is a left subtree node of a node or not ...if so the that node will be the inorder successor
		return;
	}
	
	if(!itr)
	inordersuccessor(root->right,key,next,itr,x);
	
	if(itr&&!next)
	{
		if(root->left==x)
		next=root;
		x=root;
	}
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(10,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(11,&root);
	inorder(root);
	Node* next=NULL,*x=NULL;
	bool itr=0;
	inordersuccessor(root,11,next,itr,x);cout<<"Inorder successor of 11 is "<<((next)?next->data:0)<<endl<<endl;
	next=x=NULL;itr=0;
	inordersuccessor(root,17,next,itr,x);cout<<"Inorder successor of 17 is "<<((next)?next->data:0)<<endl<<endl;
	next=x=NULL;itr=0;
	inordersuccessor(root,7,next,itr,x);cout<<"Inorder successor of 7 is "<<((next)?next->data:0)<<endl<<endl;
	return 0;
}
