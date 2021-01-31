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
void getancestorarray(Node* root,int arr[])
{
	arr[0]=-1;
	
	queue<Node*> q;
	q.push(root);
	
	while(q.size())
	{
		if(q.front()->left)
		{
			arr[q.front()->left->data]=q.front()->data;
			q.push(q.front()->left);
		}
		if(q.front()->right)
		{
			arr[q.front()->right->data]=q.front()->data;
			q.push(q.front()->right);
		}
		q.pop();
	}
}
void kthAncestor(Node* root,int x,int k,int n)
{
	int arr[n+1];
	getancestorarray(root,arr);
	
	while(x!=-1)
	{
		x=arr[x];
		k--;
		if(k==0)
		break;
	}
	cout<<x<<endl;
}
signed main()
{ 
	Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
  
    int k = 2;
    int node = 5;
    int size=5;
    
    kthAncestor(root,node,k,size);
    
    return 0;
}
