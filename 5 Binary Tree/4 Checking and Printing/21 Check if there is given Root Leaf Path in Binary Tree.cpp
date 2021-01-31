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
bool ispresent(Node* root,int arr[],int ind,int n)
{
	if(!root)
	return (ind==n);
	
	if(root->data!=arr[ind++])
	return false;
	
	if(ispresent(root->left,arr,ind,n))
	return true;
	
    return ispresent(root->right,arr,ind,n);
}
signed main()
{
	int arr[] = {5, 8, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    
    if(ispresent(root, arr, 0, n))
    cout << "Present";
    else
    cout << "Not Present";
    
    return 0; 
}
