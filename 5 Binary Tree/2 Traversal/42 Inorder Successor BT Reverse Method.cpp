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
void inordersuccessor(Node* root,int key,Node* &next,bool &itr)
{
	if(itr||!root)
	return;
	inordersuccessor(root->right,key,next,itr);
	
	if(root->data==key)
	itr=!itr;
	
	if(!itr)
	next=root;
	
	inordersuccessor(root->left,key,next,itr);
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(10,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(11,&root);
	inorder(root);
	Node* next=NULL;
	bool itr=0;
	inordersuccessor(root,11,next,itr);cout<<"Inorder successor of 11 is "<<((next)?next->data:0)<<endl<<endl;
	next=NULL;itr=0;
	inordersuccessor(root,17,next,itr);cout<<"Inorder successor of 17 is "<<((next)?next->data:0)<<endl<<endl;
	next=NULL;itr=0;
	inordersuccessor(root,7,next,itr);cout<<"Inorder successor of 7 is "<<((next)?next->data:0)<<endl<<endl;
	return 0;
}
