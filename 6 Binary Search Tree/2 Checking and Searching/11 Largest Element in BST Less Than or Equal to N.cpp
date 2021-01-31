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
Node* insert(Node* root, int key)
{
    if (!root)
    root = new Node(key);
    
    else if (root->data > key)
    root->left = insert(root->left, key);
    
    else if (root->data < key)
    root->right = insert(root->right, key);
    
    return root;
}
int findMaxforN(Node* root,int N)
{
	int ans=-1;
	
	while(root && root->data!=N)
	{
		if(root->data < N)
		{
			ans=root->data;
			root=root->right;
		}
		else
		root=root->left;
	}
	if(!root)
	return ans;
	else
	return N;
}
signed main()
{
    int N = 10;
    // creating following BST 
    /* 
                  5 
               /   \  
             2     12 
           /  \    /  \  
          1   3   9   21 
                     /   \   
                    19   25  */
    
    Node* root=NULL;
	root = insert(root, 25);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 12);
    insert(root, 9);
    insert(root, 21);
    insert(root, 19);
    insert(root, 25);

    printf("%d", findMaxforN(root, N));
    
    return 0;
}
