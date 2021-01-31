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
void traverse(Node* root,int sum,int &maxsum,int h,int &maxh)
{
	if(!root)
	return;
	
	sum+=root->data;
	
	if(!root->left && !root->right && h>=maxh)
	{
		h=maxh;
		maxsum=max(sum,maxsum);
	}
	
	traverse(root->left,sum,maxsum,h+1,maxh);
	traverse(root->right,sum,maxsum,h+1,maxh);
}
int sumOfLongRootToLeafPathUtil(Node* root)
{
	int maxsum=0,maxh=0;
	traverse(root,0,maxsum,0,maxh);
	return maxsum;
}
signed main()
{
	Node* root = new Node(4);         /*        4        */
    root->left = new Node(2);         /*       / \       */
    root->right = new Node(5);        /*      2   5      */
    root->left->left = new Node(7);   /*     / \ / \     */
    root->left->right = new Node(1);  /*    7  1 2  3    */
    root->right->left = new Node(2);  /*      /          */
    root->right->right = new Node(3); /*     6           */
    root->left->right->left = new Node(6);
  
    cout << "Sum = "<< sumOfLongRootToLeafPathUtil(root); 
    
    return 0; 
}
