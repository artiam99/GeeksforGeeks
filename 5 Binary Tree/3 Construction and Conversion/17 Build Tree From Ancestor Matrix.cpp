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
Node* ancestorTree(int m[][6],int n)
{
	vector<int> pref;
	
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=0;j<n;j++)
		sum+=m[i][j];
		pref.push_back(sum);
	
	}
	
	vector<Node*> tree;
	for(int i=0;i<n;i++)
	{
		Node* temp=new Node(i);
		tree.push_back(temp);
	}
	
	Node* root=NULL;
	
	for(int i=0;i<n;i++)
	{
		int p=-1;
		for(int j=0;j<n;j++)
		{
			if(m[j][i]==1)
			{
				if(p==-1||pref[j]<pref[p])
				p=j;
			}
		}
		if(p==-1)
		root=tree[i];
		
		else
		{
			if(!tree[p]->left)
			tree[p]->left=tree[i];
			else
			tree[p]->right=tree[i];
		}
	}
	
	return root;
}
signed main()
{
	int mat[6][6] = {{ 0, 0, 0, 0, 0, 0 },
                     { 1, 0, 0, 0, 1, 0 },
                     { 0, 0, 0, 1, 0, 0 },
                     { 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0 },
                     { 1, 1, 1, 1, 1, 0 }
                    };
    Node* root = ancestorTree(mat,6);
	
	inorder(root);
	
	return 0;
}
