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
bool kthAncestorDFS(Node* root,int x,int &k)
{
	if(!root)
	return false;
	
	if(root->data==x)
	{
		k--;
		return true;
	}
	
	if(kthAncestorDFS(root->left,x,k)||kthAncestorDFS(root->right,x,k))
	{
		if(k==0)
		cout<<root->data<<endl;

		k--;
		return true;
	}
	return false;
}
signed main()
{ 
	Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
  
    int k = 2;
    int node = 5;

    kthAncestorDFS(root,node,k);
    
    if(k>=0)
    cout<<-1<<endl;
    
    return 0;
}
