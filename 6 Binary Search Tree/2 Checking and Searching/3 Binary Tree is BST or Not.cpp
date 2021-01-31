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
void checkuntill(Node* root,int l,int r,bool &b)
{
	if(!b || !root)
	return;
	
	if(root->data <l || root->data >r)
	b=0;
	
	checkuntill(root->left,l,root->data-1,b);
	checkuntill(root->right,root->data+1,r,b);
}
bool check(Node* root)
{
	bool b=1;
	checkuntill(root,INT_MIN,INT_MAX,b);
	return b;
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
    
    if(check(root))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    
    return 0;
}
