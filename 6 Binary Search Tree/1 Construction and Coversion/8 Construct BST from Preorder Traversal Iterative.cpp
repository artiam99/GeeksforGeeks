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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* construct(int pre[],int n)
{
	Node* root=NULL,*temp,*temp2;
	stack<Node*> st;
	for(int i=0;i<n;i++)
	{
		temp=new Node(pre[i]);
		
		if(!root)
		root=temp;
		
		if(st.size())
		{
			if(st.top()->data > pre[i])
			st.top()->left=temp;
			
			else
			{
				while(st.size() && st.top()->data < pre[i])
				{
					temp2=st.top();
					st.pop();
				}
				temp2->right=temp;
			}
		}
		st.push(temp);
	}
	return root;
}
signed main()
{
	int pre[]={10,5,1,7,40,50};
	int n=sizeof(pre)/sizeof(int);
	
	Node* root=construct(pre,n);
	inorder(root);
	
	return 0;
}
