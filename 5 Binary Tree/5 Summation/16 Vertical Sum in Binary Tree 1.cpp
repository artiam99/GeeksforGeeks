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
void traverse(Node* root,map<int,int> &m,int v)
{
	if(!root)
	return;
	
	m[v]+=root->data;
	
	traverse(root->left,m,v-1);

	traverse(root->right,m,v+1);
}
vector<int> verticalSumDLL(Node* root)
{
	vector<int> a;
	if(!root)
	return a;
	
	map<int,int> m;
	
	traverse(root,m,0);
	
	for(auto i:m)
	a.push_back(i.second);
	
	return a;
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

    
	vector<int>a=verticalSumDLL(root);
    cout << "Vertical Sums are\n";
    for(auto i:a)
    cout<<i<<" ";
    cout<<endl;
    
    return 0;
}
