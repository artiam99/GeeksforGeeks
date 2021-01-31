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
bool check(Node* root)
{
	if(!root)
	return true;
	
	if(!root->left&&!root->right)
	return true;
	
	if(!root->right&&root->left&&root->left->data==root->data)
	return check(root->left);
	
	if(!root->left&&root->right&&root->right->data==root->data)
	return check(root->right);
	
	if(root->left->data+root->right->data==root->data && check(root->left) && check(root->right))
	return true;
	
	return false;
}
signed main()
{
	Node *root = new Node(10);
    root->left     = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);
    
    if(check(root))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
    
	return 0;
}
