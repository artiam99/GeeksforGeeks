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
int getMaxWidth(Node* root)
{
    int mx=0;
    
    queue<Node*> q;
    if(root)
    q.push(root);
    
    while(q.size())
    {
        int size=q.size();
        int i=0;
        while(size--)
        {
            i++;
            if(q.front()->left)
            q.push(q.front()->left);
            if(q.front()->right)
            q.push(q.front()->right);
            q.pop();
        }
        mx=max(mx,i);
    }
    return mx;
}
signed main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);
    
    /*
             1
            / \
           2   3
         /  \   \
        4    5   8
                / \
                6 7 
    */
    cout<<"Maximum width is "<< getMaxWidth(root)<<endl;
    return 0;
}
