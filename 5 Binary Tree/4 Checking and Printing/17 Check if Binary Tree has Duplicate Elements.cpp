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
bool Traverse(Node* root,unordered_set<int> &s)
{
	if(!root)
	return false;
	
	if(s.find(root->data)!=s.end())
	return true;
	
	s.insert(root->data);
	
	return (Traverse(root->left,s) || Traverse(root->right,s));
}
bool Check(Node* root)
{
    
    unordered_set<int> s;
    return Traverse(root,s);
    
}
signed main()
{
    Node *root = new Node(1);
    root->left     = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    if (Check(root))
    cout << "YES";
    else
    cout << "NO";
  
    return 0;
}
