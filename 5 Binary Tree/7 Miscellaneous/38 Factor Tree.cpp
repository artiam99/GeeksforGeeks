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
		int size=q.size();
		while(size--)
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
}
Node* construct(int val)
{
	if(val==1)
	return NULL;
	
	int f=1;
	for(int i=2;i<val/2;i++)
	if(val%i==0)
	{
		f=i;
		break;
	}
	
	Node* root=new Node(val);
	
	if(f==1)
	return root;
	
	root->left=construct(f);
	root->right=construct(val/f);
	return root;
}
signed main()
{
	int val=48;

    Node *root = construct(val);
    
    BFT(root);
    
    return 0;
}
