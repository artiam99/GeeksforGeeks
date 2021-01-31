#include<bits/stdc++.h>
using namespace std;
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
pair<int,int> traverse(Node* root,int l,int r,int &c)
{
	if(!root)
	return {0,0};
	
	pair<int,int> p1=traverse(root->left,l,r,c);
	pair<int,int> p2=traverse(root->right,l,r,c);
	
	int left=(root->left)?p1.first:root->data;
	int right=(root->right)?p2.second:root->data;
	
	if(left >=l && right <=r)
	c++;
	
	return {left,right};
}
int getCount(Node* root,int l,int r)
{
	int c=0;
	traverse(root,l,r,c);
	return c;
}
signed main()
{
    /*
          10 
        /    \ 
      5       50 
     /       /  \ 
    1       40   100   */
	
    Node* root = new Node(10); 
    root->left = new Node(5); 
    root->right = new Node(50); 
    root->left->left = new Node(1); 
    root->right->left = new Node(40); 
    root->right->right = new Node(100); 

    int l = 1 , h = 45; 
    
	cout << "Count of subtrees in [" << l << ", "<< h << "] is " << getCount(root, l, h); 
    
	return 0; 
}
