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
bool found(Node* root,vector<int> &a,int x)
{
	if(!root)
	return false;
	
	a.push_back(root->data);
	
	if(root->data==x)
	return true;
	
	if(found(root->left,a,x) || found(root->right,a,x))
	return true;
	
	a.pop_back();
	
	return false;
}
void printPath(Node* root,int x)
{
	vector<int> a;
	
	if(found(root,a,x))
	for(auto i:a)
	cout<<i<<" ";
	
	else
	cout<<"No Path";
	cout<<endl;
}
signed main()
{
	Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
          
    int x = 5;
    
    printPath(root, x);
    
    return 0;
}
