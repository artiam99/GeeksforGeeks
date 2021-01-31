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
void traverse(Node* root,int &ans,int &c,int k)
{
	if(!root || ans!=-1)
	return;
	
	traverse(root->left,ans,c,k);
	
	c++;
	
	if(c==k)
	ans=root->data;
	
	traverse(root->right,ans,c,k);
}
int KthSmallest(Node* root,int k)
{
	int ans=-1,c=0;
	traverse(root,ans,c,k);
	return ans;
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
    
    int k=5;
    
    cout<<KthSmallest(root,k)<<endl;
    
    return 0;
}
