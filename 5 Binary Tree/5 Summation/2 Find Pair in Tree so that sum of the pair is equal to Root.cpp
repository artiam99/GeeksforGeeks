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
void find(Node* root,unordered_set<int> &s,vector<pair<int,int>> &a,int x)
{
	if(!root)
	return;
	
	if(s.find(root->data)==s.end())
	{
		if(s.find(x-root->data)!=s.end())
		a.push_back({root->data,x-root->data});
		
		s.insert(root->data);
	}
	find(root->left,s,a,x);
	find(root->right,s,a,x);
}
void FindPair(Node* root)
{
	unordered_set<int> s;
	vector<pair<int,int>> a;
	
	find(root->left,s,a,root->data);
	find(root->right,s,a,root->data);
	
	for(auto i:a)
	cout<<i.first<<" "<<i.second<<endl;
}
signed main()
{
	Node *root = new Node(8);
    root->left    = new Node(5);
    root->right   = new Node(4);
    root->left->left = new Node(9);
    root->left->right = new Node(7);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(12);
    root->left->right->right->right = new Node(2);
    root->right->right = new Node(11);
    root->right->right->left = new Node(3);

    FindPair(root);
    
    return 0; 
}
