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
void traverse(Node* root,int &sum)
{
	if(!root)
	return;
	
	sum+=root->data;
	
	traverse(root->left,sum);
	
	traverse(root->right,sum);
}
bool check(Node* root)
{
	int left_boundary_sum=0;
	
	Node* curr=root->left;
	while(curr)
	{
		left_boundary_sum+=curr->data;
		if(curr->left)
		curr=curr->left;
		
		else if(curr->right)
		curr=curr->right;
		
		else
		curr=NULL;
	}
	
	int right_boundary_sum=0;
	
	curr=root->right;
	while(curr)
	{
		right_boundary_sum+=curr->data;
		
		if(curr->right)
		curr=curr->right;
		
		else if(curr->left)
		curr=curr->left;
		
		else
		curr=NULL;
	}
	
	int uncovered_node_sum=left_boundary_sum+right_boundary_sum+root->data;
	
	int sum=0;
	traverse(root,sum);
	
	int covered_node_sum = sum - uncovered_node_sum;
	
	cout<<"Covered Node Sum : "<<covered_node_sum<<endl<<endl<<"Uncovered Node Sum : "<<uncovered_node_sum<<endl<<endl;
	
	if(covered_node_sum == uncovered_node_sum)
	return true;
	
	return false;
}
signed main()
{
	Node *root  = new Node(26); 
    root->left         = new Node(10); 
    root->right        = new Node(3); 
    root->left->left   = new Node(4); 
    root->left->right  = new Node(6); 
    root->right->right = new Node(3);
    
    if(check(root))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
    
	return 0;
}
