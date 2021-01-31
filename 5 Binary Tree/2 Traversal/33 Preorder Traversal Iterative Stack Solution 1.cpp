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
void preorder(Node* root)// Space Complexity is high O(h)
{
	stack<Node*> s;
	
	if(root)
	s.push(root);

	while(s.size())
	{
	    root=s.top();s.pop();
	    
		cout<<root->data<<" ";
	    
		if(root->right)
	    s.push(root->right);
	    
		if(root->left)
	    s.push(root->left);
	}
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	preorder(root);
	return 0;
}
