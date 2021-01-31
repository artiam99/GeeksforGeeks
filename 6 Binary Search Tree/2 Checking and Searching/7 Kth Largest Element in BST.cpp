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
int KthSmallest(Node* root,int k)
{
	int c=0;
	Node* curr=root,*pre;
	while(curr)
	{
		if(!curr->right)
		{
			c++;
			if(c==k)
			return curr->data;
			curr=curr->left;
		}
		else
		{
			pre=curr->right;
			while(pre->left&&pre->left!=curr)
			pre=pre->left;
			
			if(!pre->left)
			{
				pre->left=curr;
				curr=curr->right;
			}
			else
			{
				c++;
				if(c==k)
				return curr->data;
				pre->left=NULL;
				curr=curr->left;
			}
		}
	}
	return -1;
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
