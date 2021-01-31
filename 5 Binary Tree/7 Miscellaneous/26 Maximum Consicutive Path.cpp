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
void traverse(Node* root,vector<int> a,vector<int> &mx)
{
	if(!root)
	return;
	
	a.push_back(root->data);
	
	if(a.size()>1 && a.size()>mx.size())
	mx=a;
	
	if(root->left && root->left->data-root->data==1)
	traverse(root->left,a,mx);
	else
	traverse(root->left,vector<int>(),mx);
	
	
	if(root->right && root->right->data-root->data==1)
	traverse(root->right,a,mx);
	else
	traverse(root->right,vector<int>(),mx);
}
void maxConsecutivePath(Node* root)
{
	vector<int> mx;
	vector<int> a;
	traverse(root,a,mx);
	for(auto i:mx)
	cout<<i<<" ";
	cout<<endl;
}

void traverse2(Node* root,int a,int &mx)
{
	if(!root)
	return;
	
	a++;
	if(a>1&&a>mx)
	mx=a;
	
	if(root->left && root->left->data -root->data==1)
	traverse2(root->left,a,mx);
	else
	traverse2(root->left,0,mx);
	
	if(root->right && root->right->data-root->data==1)
	traverse2(root->right,a,mx);
	else
	traverse2(root->right,0,mx);
}
void maxConsecutivePathLength(Node* root)
{
	int mx=0;
	traverse2(root,0,mx);
	cout<<"Maximum Path Length : "<<mx<<endl;
}
signed main()
{
	/*   	10
	      /    \     
	     /      \
	    11        9    
	   / \        /\
	  /   \      /  \
	13    12    13   8*/
	Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(13);
    root->left->right = new Node(12);
    root->right->left = new Node(13);
    root->right->right = new Node(8);
    
    maxConsecutivePathLength(root);
    maxConsecutivePath(root);
    
    return 0; 
}
