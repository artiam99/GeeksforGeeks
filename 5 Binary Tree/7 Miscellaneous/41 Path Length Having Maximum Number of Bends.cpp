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
void traverse(Node* root,bool b,int &mxh,int h,int &mxb,int bend)
{
	if(!root)
	return;
	if(!root->left && !root->right && bend>mxb)
	{
		mxb=bend;
		mxh=h;
		return;
	}
	traverse(root->left,0,mxh,h+1,mxb,(b)?bend+1:bend);
	traverse(root->right,1,mxh,h+1,mxb,(b)?bend:bend+1);
}
int findPathLength(Node* root)
{
	if(!root)
	return 0;
	
	int mxb=0;
	int mxh=0;
	traverse(root->left,0,mxh,1,mxb,0);
	traverse(root->right,1,mxh,1,mxb,0);
	return mxh;
}
signed main()
{
    /*      4
          /   \
        2      6
      /  \    / \
    1     3  5   7
                /
               9
              / \
             12 10
                  \
                  11
                  / \
                45  13
                      \
                      14  */
                      
    Node* root=new Node(4);
	root->left=new Node(2);
	root->left->left=new Node(1);
	root->left->right=new Node(3);
	root->right=new Node(6);
	root->right->left=new Node(5);
	root->right->right=new Node(7);
	root->right->right->left=new Node(9);
	root->right->right->left->left=new Node(12);
	root->right->right->left->right=new Node(10);
	root->right->right->left->right->right=new Node(11);
	root->right->right->left->right->right->left=new Node(45);
	root->right->right->left->right->right->right=new Node(13);
	root->right->right->left->right->right->right->right=new Node(14);
	
	cout<<findPathLength(root)<<endl;
	
    return 0;
}
