#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	char data;
	Node* left;
	Node* right;
    Node(char x)
	{
		data=x;
		left=right=NULL;
	}
};
string preorder(Node* root,unordered_map<string,int> &mp)
{
    string s;
    if(!root)
    {
        s+="$";
        return s;
    }
    s+=root->data;
    s+=preorder(root->left,mp);
    s+=preorder(root->right,mp);
    mp[s]++;
    return s;
}
bool isDuplicate(Node* root)
{
	unordered_map<string,int> mp;
    preorder(root,mp);
    for(auto i:mp)
    if(i.second>=2&&i.first.length()>3)
    return true;
    return false;
}
signed main()
{
	Node *root = new Node('A'); 
    root->left = new Node('B'); 
    root->right = new Node('C'); 
    root->left->left = new Node('D'); 
    root->left->right = new Node('E'); 
    root->right->right = new Node('B'); 
    root->right->right->right = new Node('E'); 
    root->right->right->left= new Node('D'); 
    
    if(isDuplicate(root))
    cout << "Yes";
    else
    cout << "No";
    
    return 0; 
}
