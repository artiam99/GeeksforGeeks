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
bool traverse(Node* root,vector<int> &a,int sum,int &maxsum)
{
	if(!root)
	return false;
	
	sum+=root->data;
	
	if(!root->left && !root->right && sum > maxsum)
	{
		maxsum=sum;
		
		a.clear();
		
		a.push_back(root->data);
		return true;
	}
	
	bool l=traverse(root->left,a,sum,maxsum);
	bool r=traverse(root->right,a,sum,maxsum);
	
	if(l||r)
	{
		a.push_back(root->data);
		return true;
	}
	
	return false;
}
int maxSumPath(Node* root)
{
	vector<int> a;
	int maxsum=intmin;
	traverse(root,a,0,maxsum);
	
	for(auto i=a.rbegin();i!=a.rend();i++)
	cout<<*i<<" ";
	cout<<endl;
	
	return maxsum;
}
signed main()
{
	Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);

    cout << "Following are the nodes on the maximum sum path \n";
    int sum = maxSumPath(root);
    cout << "\nSum of the nodes is " << sum;
    
    return 0; 
}
