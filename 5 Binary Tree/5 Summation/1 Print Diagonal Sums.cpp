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
void diagonalSumuntill(Node* root,map<int,int> &m,int l=0)
{
	if(!root)
	return;
	
	m[l]+=root->data;
	diagonalSumuntill(root->left,m,l+1);
	diagonalSumuntill(root->right,m,l);
}
void diagonalSum(Node* root)
{
	map<int,int> m;
	diagonalSumuntill(root,m);
	
	for(auto i:m)
	cout<<i.second<<endl;
}
signed main()
{
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(6);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->right = new Node(7);
    root->right->left->left = new Node(12);
    root->left->right->left = new Node(11);
    root->left->left->right = new Node(10);

    diagonalSum(root);
    
    return 0; 
}
