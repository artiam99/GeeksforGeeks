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
void printVerticalOrder(Node* root)
{
	if(!root)
	return;

    map<int,vector<int>> m;
   
    queue<pair<Node*,int>> q;
    
	q.push({root,0});
    
	while(q.size())
    {
        m[q.front().second].push_back(q.front().first->data);
        
		if(q.front().first->left)
        q.push({q.front().first->left,q.front().second-1});
        
		if(q.front().first->right)
        q.push({q.front().first->right,q.front().second+1});
        
		q.pop();
    }
    for(auto i:m)
    {
        for(auto j:i.second)
        cout<<j<<" ";
        cout<<endl;
    }
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
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left= new Node(10);
    root->right->right->left->right= new Node(11);
    root->right->right->left->right->right= new Node(12);
    
    cout << "Vertical order traversal is \n";
    
    printVerticalOrder(root);
}
