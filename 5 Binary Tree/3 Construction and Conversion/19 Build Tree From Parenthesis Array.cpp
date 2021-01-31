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
void preorder(Node* root)
{
	if(!root)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Node* buildTree(string s)
{
	Node* root=NULL;
	
	stack<Node*> st;
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			Node* temp=new Node(s[i]-48);
			if(!root)
			root=temp;
			st.push(temp);
		}
		else
		{
			if(s[i]==')')
			{
				Node* temp=st.top();
				st.pop();
				if(!st.top()->left)
				st.top()->left=temp;
				else
				st.top()->right=temp;
			}
		}
	}
	return root;
}
signed main()
{
	string s="4(2(3)(1))(6(5))";
	
	Node* root=buildTree(s);
	
	preorder(root);
	
	return 0;
}
