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
vector<Node*> constructuntill(int l,int r)
{
	vector<Node*> tree;
	if(l>r)
	{
		tree.push_back(NULL);
		return tree;
	}
	
	for(int i=l;i<=r;i++)
	{
		vector<Node*> left=constructuntill(l,i-1);
		vector<Node*> right=constructuntill(i+1,r);
		
		for(int j=0;j<left.size();j++)
		{
			for(int k=0;k<right.size();k++)
			{
				Node* root=new Node(i);
				root->left=left[j];
				root->right=right[k];
				tree.push_back(root);
			}
		}
	}
	return tree;
}
vector<Node*> construct(int N)
{
	return constructuntill(1,N);
}
signed main()
{
	int N=3;
	vector<Node*> tree=construct(N);
	
	for(auto i:tree)
	{
		preorder(i);
		cout<<endl;
	}
	
    return 0;
}
