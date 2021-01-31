#include<bits/stdc++.h>
using namespace std;
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
Node* insert(Node* root,int x)
{
	if(!root)
	return new Node(x);
	
	if(root->data<x)
	root->right=insert(root->right,x);
	
	else if(root->data>x)
	root->left=insert(root->left,x);

	return root;
}
int findmax(Node* root,int x)
{
	int p=-1;
	while(root->data!=x)
	{
		if(root->data<x)
		root=root->right;
		else
		{
			p=root->data;
			root=root->left;
		}
	}
	return p;
}
void replace(int arr[],int n)
{
	Node* root=NULL;
	
	for(int i=n-1;i>=0;i--)
	{
		root=insert(root,arr[i]);
		
		arr[i]=findmax(root,arr[i]);
    }
}
signed main()
{
    int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28 }; 
    int n = sizeof(arr)/ sizeof(arr[0]);

    replace(arr, n);

    for (int i = 0; i < n; i++)
	cout << arr[i] << " ";
    
    return 0;
}
