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
void BFT(Node* root)
{
	queue<Node*> q;
	if(root)
	q.push(root);
	while(q.size())
	{
		cout<<q.front()->data<<" ";
	    if(q.front()->left)
	    q.push(q.front()->left);
	    if(q.front()->right)
	    q.push(q.front()->right);
	    q.pop();
	}
	cout<<endl;
}
Node* buildTree(int p[], int n)
{
	Node* root=NULL;
	
	vector<Node*> a;
	
	for(int i=0;i<n;i++)
	{
		Node* temp=new Node(i);
		
		if(p[i]==-1)
		root=temp;
		
		a.push_back(temp);
	}
	
	for(int i=0;i<n;i++)
	{
		if(p[i]!=-1)
		{
			if(!a[p[i]]->left)
			a[p[i]]->left=a[i];
			
			else
			a[p[i]]->right=a[i];
		}
	}
	
	return root;
}
signed main()
{
	int parent[]={-1,0,0,1,1,3,5};
	
	int n=sizeof(parent)/sizeof(int);
	
	Node* root=buildTree(parent,n);
	
	BFT(root);
	
	return 0;
}
