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
int traverse(Node* root,int &c)
{
	if(!root)
	return -1;
	
	int l=root->data,r=root->data;
	if(root->left)
	l=traverse(root->left,c);
	
	if(root->right)
	r=traverse(root->right,c);
	
	if((l==r)&&l==root->data)
	{
		c++;
		return root->data;
	}
	return -1;
}
int countSingle(Node* root)
{
	int c=0;
	traverse(root,c);
	return c;
}
signed main()
{
    /*
            5 
          /   \ 
        4      5 
      /  \      \ 
     4    4      5 */
    Node* root        = new Node(5);
    root->left        = new Node(4);
    root->right       = new Node(5);
    root->left->left  = new Node(4);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    cout << "Count of Single Valued Subtrees is "<< countSingle(root);
    
    return 0;
}
