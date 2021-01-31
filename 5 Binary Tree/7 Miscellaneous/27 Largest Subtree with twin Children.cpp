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
int traverse(Node* root,string &s,int &maxsize,Node* &maxNode)
{
	if(!root)
	return 0;
	
	string sl,sr;
	
	int size=traverse(root->left,sl,maxsize,maxNode)+traverse(root->right,sr,maxsize,maxNode)+1;
	
	if(sl.compare(sr)==0)
	{
		if(size>maxsize)
		{
			maxNode=root;
			maxsize=size;
		}
	}
	
	s.append("|").append(sl).append("|");
	s.append("|").append(to_string(root->data)).append("|");
	s.append("|").append(sr).append("|");
	
	return size;
}
int largestSubtree(Node* root,Node* &maxNode)
{
	string s;
	int maxsize=0;
	traverse(root,s,maxsize,maxNode);
	return maxsize;
}
signed main()
{
    /*
                50 
              /     \ 
             10      60 
            / \     /  \ 
            5 20   70   70 
                   / \  / \ 
                  65 80 65 80   */
    Node* root = new Node(50);
    root->left = new Node(10);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(70);
    root->right->left->left = new Node(65);
    root->right->left->right = new Node(80);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    Node *maxNode = NULL;
    int maxSize = largestSubtree(root, maxNode);

    cout << "Largest Subtree is rooted at node "<< maxNode->data << "\nand its size is "<< maxSize;

    return 0;
}
