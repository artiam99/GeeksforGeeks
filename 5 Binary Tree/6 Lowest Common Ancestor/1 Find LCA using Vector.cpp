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
bool path(Node* root,vector<int> &a,int x)
{
	if(!root)
	return false;
	
	a.push_back(root->data);
	
	if(root->data==x)
	return true;
	
	if(path(root->left,a,x)||path(root->right,a,x))
	return true;
	
	a.pop_back();
	return false;
}
int findLCA(Node* root,int a,int b)
{
	vector<int> A,B;
	
	path(root,A,a);
	path(root,B,b);
	
	if(A[A.size()-1]!=a||B[B.size()-1]!=b)
	return -1;
	
	int i;
	for(i=0;i<A.size()&&i<B.size();i++)
	if(A[i]!=B[i])
	break;
	
	return A[i-1];
}
signed main()
{
	Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)<<endl;
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)<<endl;
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)<<endl;
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)<<endl;
    
    return 0;
}
