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
Node* findlca(Node* root,int first,int second)
{
    if(!root)
    return NULL;
    
    if(root->data ==first || root->data == second)
    return root;
    
    Node* left=findlca(root->left,first,second);
    Node* right=findlca(root->right,first,second);
    
    if(left && right)
    return root;
    
    return (left)?left:right;
}
void findbends(Node* root,int target,bool b,int &ans,int bend)
{
    if(!root)
    return;
    if(root->data==target)
    ans=bend;
    findbends(root->left,target,0,ans,(b)?bend+1:bend);
    findbends(root->right,target,1,ans,(b)?bend:bend+1);
}
int NumberOFTurns(Node* root, int first, int second)
{
    Node* lca=findlca(root,first,second);
    int f=-1,s=-1;
    
    if(root->data==first)
    f=0;
    if(root->data==second)
    s=0;
    
    findbends(lca->left,first,0,f,0);
    findbends(lca->right,first,1,f,0);
    
    findbends(lca->left,second,0,s,0);
    findbends(lca->right,second,1,s,0);
    
    if(f==-1 || s==-1)
    return -1;
    
    if(lca->data!=first&&lca->data!=second)
    return f+s+1;
    if(f+s)
    return f+s;
}
signed main()
{
	/*
	               1
                /     \
               2        3
             /   \    /   \
            4     5   6     7
           /         / \
          8         9   10
	*/
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(10);

    int turn = NumberOFTurns(root, 5, 10);
    
    if ( turn != -1)
    cout << turn << endl;
    else
    cout << "Not Possible" << endl;
    
    return 0;
}
