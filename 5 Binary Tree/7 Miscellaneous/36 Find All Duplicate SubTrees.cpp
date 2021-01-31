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
string traverse(Node* root , unordered_map<string,pair<int,int>> &m)
{
    string s;
    
    if(!root)
    return s;
    
    string sl=traverse(root->left,m);
    string sr=traverse(root->right,m);
    
    s+="."+sl+".";
    s+="."+to_string(root->data)+".";
    s+="."+sr+".";
    
    if(m.find(s)==m.end())
    m[s]={root->data,1};
    
    else
    m[s].second++;
    
    return s;
}
void printAllDups(Node* root)
{
    unordered_map<string,pair<int,int>> m;
    
    traverse(root,m);
    
    priority_queue<int,vector<int>,greater<int>> p;
   
    for(auto i:m)
        if(i.second.second>1)
        p.push(i.second.first);
    
    if(p.empty())
    cout<<-1;
    
    while(p.size())
        cout<<p.top()<<" ",p.pop();
}
signed main()
{
	/* 1
	  / \
	 2   3
	/   / \
	4   2   4
	  /
	 4       */
	 
    Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);
    root->right->right = new Node(4);
    
    printAllDups(root);
    
    return 0;
}
