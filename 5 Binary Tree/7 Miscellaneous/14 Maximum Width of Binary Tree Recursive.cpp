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
void traverse(Node* root,vector<int> &a,int h=0)
{
    if(!root)
    return;
    if(a.size()==h)
    a.push_back(1);
    else
    a[h]++;
    traverse(root->left,a,h+1);
    traverse(root->right,a,h+1);
}
int getMaxWidth(Node* root)
{
    vector<int> a;
    traverse(root,a);
    return *max_element(a.begin(),a.end());
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
