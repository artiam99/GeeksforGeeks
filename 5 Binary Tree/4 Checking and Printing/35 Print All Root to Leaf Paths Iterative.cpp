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
void printPaths(Node* root)
{
	stack<pair<Node*,int>> st;
	
	vector<int> a;
	
	if(root)
	st.push({root,0});
	
	while(st.size())
	{
		if(st.top().second==0)
		{
			st.top().second=1;
			
			a.push_back(st.top().first->data);
			
			if(st.top().first->left)
			st.push({st.top().first->left,0});
		}
		else if(st.top().second==1)
		{
			st.top().second=2;
			
			if(st.top().first->right)
			st.push({st.top().first->right,0});
		}
		else
		{
			if(!st.top().first->left&&!st.top().first->right)
			{
				for(auto i:a)
				cout<<i<<" ";
				cout<<endl;
			}
			st.pop();
			a.pop_back();
		}
	}
}
signed main()
{
	Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
    
    printPaths(root);
    
    return 0;
}
