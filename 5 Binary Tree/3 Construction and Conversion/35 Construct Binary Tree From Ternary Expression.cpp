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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* construct(string s,int &i)
{
	Node* root=new Node(s[i]);
	
	if(i==s.length()-1)
	return root;
	
	if(s[i+1]=='?')
	{
		i+=2;
		root->left=construct(s,i);
		root->right=construct(s,i);
	}
	
	else
	i+=2;
	
	return root;
}
signed main()
{
	string s="a?b?c:d:e";
	
	int ind=0;
	Node* root=construct(s,ind);
	
	inorder(root);
	return 0;
}
