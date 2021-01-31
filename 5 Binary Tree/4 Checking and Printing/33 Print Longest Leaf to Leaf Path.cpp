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
void reverse(vector<int> &a)
{
	int l=0,r=a.size()-1;
	while(l<r)
	{
		swap(a[l],a[r]);
		l++;
		r--;
	}
}
vector<int> traverse(Node* root,vector<int> &a)
{
	if(!root)
	return vector<int>();
	
	vector<int> l=traverse(root->left,a);
	vector<int> r=traverse(root->right,a);
	
	if(l.size()+r.size()+1>a.size())
	{
		a=l;
		
		a.push_back(root->data);
		
		for(int i=r.size()-1;i>=0;i--)
		a.push_back(r[i]);
	}
	if(l.size()>=r.size())
	{
		l.push_back(root->data);
		return l;
	}
	else
	{
		r.push_back(root->data);
		return r;
	}
}
void PrintDiameter(Node* root)
{
	vector<int> a;
	
	traverse(root,a);
	
	for(auto i:a)
	cout<<i<<" ";
	cout<<endl;
}
signed main()
{
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6); 
    root->left->right->right = new Node(7); 
    root->left->left->right = new Node(8); 
    root->left->left->right->left = new Node(9);
    
    PrintDiameter(root);
    
    return 0; 
}
