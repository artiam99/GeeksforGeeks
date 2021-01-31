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
void Encode(Node* root,list<bool> &strc,list<int> &data)
{
	if(!root)
	{
		strc.push_back(0);
		return;
	}
	
	strc.push_back(1);
	data.push_back(root->data);
	
	Encode(root->left,strc,data);
	Encode(root->right,strc,data);
}
Node* Decode(list<bool> &strc,list<int> &data)
{
	if(!strc.size())
	return NULL;
	
	bool b=strc.front();
	strc.pop_front();
	
	if(b)
	{
		Node* root=new Node(data.front());
		data.pop_front();
		
		root->left=Decode(strc,data);
		root->right=Decode(strc,data);
		
		return root;
	}
	return NULL;
}
signed main()
{
    Node *root         = new Node(10); 
    root->left         = new Node(20); 
    root->right        = new Node(30); 
    root->left->left   = new Node(40); 
    root->left->right  = new Node(50); 
    root->right->right = new Node(70); 
    
    preorder(root);cout<<endl;
    
    list<bool> strc;
    list<int> data;
    
    Encode(root,strc,data);
    
    Node* root2=Decode(strc,data);
    
	preorder(root2);
	
	return 0; 
}
