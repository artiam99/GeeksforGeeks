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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void store(Node* root,vector<int> &a)
{
	if(!root)
	return;
	
	store(root->left,a);
	a.push_back(root->data);
	store(root->right,a);
}
void convertuntill(Node* root,vector<int> &a,int &i)
{
	if(!root)
	return;
	
	convertuntill(root->left,a,i);
	
	root->data=a[i++];
	
	convertuntill(root->right,a,i);
}
void convert(Node* root)
{
	vector<int> a;
	
	store(root,a);
	
	sort(a.begin(),a.end());
	
	int i=0;
	convertuntill(root,a,i);
}
signed main()
{
	/*
           5 
         /   \ 
        7     9 
       /\    / \ 
      1  6   10 11   */
	
	Node* root = new Node(5);
    root->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(11);
	
	convert(root);
	
	inorder(root);
	
	return 0;
}
