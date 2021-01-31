#include<bits/stdc++.h>
using namespace std;
#define int long long
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
Node* constructet(char s[])
{
	stack<Node*> st;
	for(int i=0;i<strlen(s);i++)
	{
		Node* temp=new Node(s[i]);
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
		{
			temp->right=st.top();st.pop();
			temp->left=st.top();st.pop();
	    }
	    st.push(temp);
	}
	return st.top();
}
void printinfix(Node* root)
{
	if(!root)
	return;
	printinfix(root->left);
	cout<<root->data<<" ";
	printinfix(root->right);
}
signed main()
{
	char postfix[]="ab+ef*g*-";
	for(int i=0;i<strlen(postfix);i++)
	cout<<postfix[i]<<" ";cout<<endl;
	Node* root=constructet(postfix);
	printinfix(root);cout<<endl;
	return 0;
}
