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
int traverse(Node* root,int &size)
{
	if(!root)
	return 0;

	size++;

	return max(traverse(root->left,size)+1,traverse(root->right,size)+1);
}
bool isPerfect(Node* root)
{
	int size=0;
	int height=traverse(root,size);
	if(size==pow(2,height)-1)
	return true;
	return false;
}
signed main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
  
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
  
    if (isPerfect(root)) 
    printf("Yes\n"); 
    else
    printf("No\n"); 
  
    return 0; 
}
