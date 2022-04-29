#include<bits/stdc++.h>
using namespace std;
#define int long long

//           1
//        /   \
//      2         0
//   /   \      /
// 3       1    6

struct Node
{
    int val;
    Node *left, *right;

    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

// This function returns maximum length of path that starts from root and maintains an AP sequence with common difference diff
int rec(Node* root, int diff, int &mx)
{
    if(!root->left && !root->right)
        return 1;

	// left and right path lengths with commonn difference diff
    int l = 1, r = 1;

    int ll, rr;

    if(root->left)
    {
        ll = rec(root->left, root->val - root->left->val, mx);

        if(root->val - root->left->val == diff)
            l += ll;
       
	    // ll is Length of path starts root->left with diff root - root->left 
        mx = max(mx, ll + 1);
    }

    if(root->right)
    {
        rr = rec(root->right, root->val - root->right->val, mx);

        if(root->val - root->right->val == diff)
            r += rr;
		
		// rr is Length of path starts root->right with diff root - root->right
        mx = max(mx, rr + 1);
    }

    if(root->left && root->right && 2 * root->val == root->left->val +  root->right->val)
        mx = max(mx, ll + rr + 1);

    return max(l, r);
}

int longestAP(Node* root)
{
    int mx = 1;

    rec(root, INT_MAX, mx);

    return mx;
}

signed main()
{
    Node* root = new Node(2);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(2);
    root->left->right = new Node(2);
    root->right->left = new Node(2);

    cout << longestAP(root) << endl;

    return 0;
}
