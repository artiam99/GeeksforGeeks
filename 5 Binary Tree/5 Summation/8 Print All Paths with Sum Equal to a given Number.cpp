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
void traverse(Node* root,vector<int> &a,int k)
{
	if(!root)
	return ;
	
	a.push_back(root->data);
	
	if(!root->left && !root->right)
	{
		for(int i=a.size()-1;i>=0;i--)
		{
			int sum=0;
			for(int j=i;j>=0;j--)
			{
				sum+=a[j];
				if(sum==k)
				{
					for(int p=j;p<=i;p++)
					cout<<a[p]<<" ";
					cout<<endl;
				}
			}
		}
	}
	
	traverse(root->left,a,k);
	traverse(root->right,a,k);
	
	a.pop_back();
}
int printKPath(Node* root,int k)
{
	vector<int> a;
	traverse(root,a,k);
	
}
signed main()
{
	Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printKPath(root, k);

    return 0; 
}
