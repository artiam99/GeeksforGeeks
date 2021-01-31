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
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* buildTree(int inorder[],int preorder[], int n)
{
    Node* root=NULL;
    
    stack<Node*> st;
    set<Node*> s;
    
    for(int pre=0,in=0;pre<n;)
    {
    	Node* temp=NULL;
    	do
    	{
    		temp=new Node(preorder[pre]);
    		
    		if(!root)
    		root=temp;
    		
    		if(st.size())
    		{
    			if(s.find(st.top())!=s.end())
    			{
    				st.top()->right=temp;
    				s.erase(st.top());
    				st.pop();
				}
				else
				st.top()->left=temp;
			}
			
			st.push(temp);
			
		}while(preorder[pre++]!=inorder[in]&&pre<n);
		
		temp=NULL;
		
		while(st.size() && in <n && st.top()->data==inorder[in])
		{
			temp=st.top();
			st.pop();
			in++;
		}
		
		if(temp)
		{
			st.push(temp);
			s.insert(temp);
		}
	}
    
	return root;
}
signed main()
{
	int in[]={9,8,4,2,10,5,10,1,6,3,13,12,7};// This fucking Thing takes care of duplicate elements also
	int pre[]={1,2,4,8,9,5,10,10,3,6,7,12,13};
	
	int n=sizeof(in)/sizeof(int);
	
	Node* root=buildTree(in,pre,n);
	
	for(int i=0;i<n;i++)
	cout<<in[i]<<" ";cout<<endl;
	inorder(root);cout<<endl<<endl;
	
	for(int i=0;i<n;i++)
	cout<<pre[i]<<" ";cout<<endl;
	preorder(root);
	
	return 0;
}
