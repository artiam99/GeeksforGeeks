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
void postorder(Node* root)
{
	if(!root)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* buildTree(int inorder[],int postorder[], int n)
{
    Node* root=NULL;
    
    stack<Node*> st;
    set<Node*> s;
    
    for(int post=n-1,in=n-1;post>=0;)
    {
    	Node* temp=NULL;
    	do
    	{
    		temp=new Node(postorder[post]);
    		
    		if(!root)
    		root=temp;
    		
    		if(st.size())
    		{
    			if(s.find(st.top())!=s.end())
    			{
    				s.erase(st.top());
    				st.top()->left=temp;
					st.pop();
				}
				else
				st.top()->right=temp;
			}
			
			st.push(temp);
			
		}while(postorder[post--]!=inorder[in]&&post>=0);
		
		temp=NULL;
		
		while(st.size() && in >=0 && st.top()->data==inorder[in])
		{
			temp=st.top();
			st.pop();
			in--;
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
	int post[]={9,8,4,10,10,5,2,6,13,12,7,3,1};
	
	int n=sizeof(in)/sizeof(int);
	
	Node* root=buildTree(in,post,n);
	
	for(int i=0;i<n;i++)
	cout<<in[i]<<" ";cout<<endl;
	inorder(root);cout<<endl<<endl;
	
	for(int i=0;i<n;i++)
	cout<<post[i]<<" ";cout<<endl;
	postorder(root);
	
	return 0;
}
