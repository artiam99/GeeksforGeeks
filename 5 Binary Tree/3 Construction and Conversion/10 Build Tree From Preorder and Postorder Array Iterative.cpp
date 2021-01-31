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
void postorder(Node* root)
{
	if(!root)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
Node* buildTree(int pre[],int post[], int n)
{
    unordered_map<int,int> m;
    
	for(int i=0;i<n;i++)
    m[post[i]]=i;
    
    stack<Node*> st;
    
	Node* root=new Node(pre[0]);
    
	st.push(root);
    
	for(int i=1;i<n;i++)
	{
		Node* temp=new Node(pre[i]);
		
		while(m[st.top()->data]<m[pre[i]])
		st.pop();
		
		if(!st.top()->left)
		st.top()->left=temp;
		
		else
		st.top()->right=temp;
		
		st.push(temp);
	}
	return root;
}
signed main()
{
	int pre[]={1, 2, 4, 8, 9, 5, 3, 6, 7};
	int post[]={8, 9, 4, 5, 2, 6, 7, 3, 1};
	
	int n=sizeof(pre)/sizeof(int);
	
	Node* root=buildTree(pre,post,n);
	
	for(int i=0;i<n;i++)
	cout<<pre[i]<<" ";cout<<endl;
	preorder(root);cout<<endl<<endl;
	
	for(int i=0;i<n;i++)
	cout<<post[i]<<" ";cout<<endl;
	postorder(root);
	
	return 0;
}
