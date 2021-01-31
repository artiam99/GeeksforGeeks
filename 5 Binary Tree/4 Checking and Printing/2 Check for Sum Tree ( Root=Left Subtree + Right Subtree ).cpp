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
int check(Node* root,bool &p)
{
	if(!root)
	return 0;
	
	int l=check(root->left,p);
	
	if(!p)
	return 0;
	
	int r=check(root->right,p);
	
	if(!p)
	return 0;
	
	if((root->left||root->right)&&l+r!=root->data)
	p=0;
	
	return l+r+root->data;
}
bool issumtree(Node* root)
{
	bool p=1;
	check(root,p);
}
signed main()
{
	Node *root  = new Node(26); 
    root->left         = new Node(10); 
    root->right        = new Node(3); 
    root->left->left   = new Node(4); 
    root->left->right  = new Node(6); 
    root->right->right = new Node(3);
    
    if(issumtree(root))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
    
	return 0;
}
