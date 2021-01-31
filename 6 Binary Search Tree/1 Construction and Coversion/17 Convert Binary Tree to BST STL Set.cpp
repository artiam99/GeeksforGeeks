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
void store(Node* root,multiset<int> &s)
{
	if(!root)
	return;
	
	store(root->left,s);
	s.insert(root->data);
	store(root->right,s);
}
void convertuntill(Node* root,multiset<int>::iterator &i)
{
	if(!root)
	return;
	
	convertuntill(root->left,i);
	
	root->data=*i++;
	
	convertuntill(root->right,i);
}
void convert(Node* root)
{
	multiset<int> s;
	
	store(root,s);
	
	multiset<int>::iterator i=s.begin();
	
	convertuntill(root,i);
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
