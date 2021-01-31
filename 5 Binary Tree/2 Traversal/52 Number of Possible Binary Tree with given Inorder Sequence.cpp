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
	if(!root)
	{
		cout<<endl<<endl;
		return;
	}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(q.size()!=1)
	{
		if(!q.front())
		{
			q.pop();
			cout<<endl;
			q.push(NULL);
			continue;
		}
		cout<<q.front()->data<<" ";
		if(q.front()->left)
		q.push(q.front()->left);
		if(q.front()->right)
		q.push(q.front()->right);
		q.pop();
	}
	cout<<endl<<endl;
}
vector<Node*> All_Possible_Inorder_Trees(vector<int> &a,int l,int r)// This is basically the number of Possible BST becauce for any number of elements inorder is same i.e. sorted order
{
	vector<Node*> Tree;
	
	if(l>r)
	{
		Tree.push_back(NULL);
		return Tree;
	}
	
	for(int i=l;i<=r;i++)
	{
		vector<Node*> LeftTree = All_Possible_Inorder_Trees(a,l,i-1);
		
		vector<Node*> RightTree = All_Possible_Inorder_Trees(a,i+1,r);
		
		for(int j=0 ; j < LeftTree.size() ; j++)
		{
			for(int k=0 ; k < RightTree.size() ; k++)
			{
				Node* root=new Node(a[i]);
				
				root->left=LeftTree[j];
				
				root->right=RightTree[k];
				
				Tree.push_back(root);
			}
		}
	}
	return Tree;
}
int Catalan(int n)
{
	int BT[n+1];
	
	memset(BT,0,sizeof(BT));
	
	BT[0]=BT[1]=1;
	
	for(int i=2;i<=n;i++)//Dynamic Programming to find Catalan's Number
	{
		for(int j=0;j<i;j++)
		BT[i]+=BT[j]*BT[i-1-j];
	}
	
	return BT[n];
}
signed main()
{
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

	vector<int> in={4,5,7};// We need to form all Possible Binary Trees with this Traversal Sequence
	                      //...Number of Possible trees is Catalan's Number...Far all Shape there is one Permutation
	int n=in.size();
    
    cout<<"Inorder Sequence : ";
    for(auto i:in)
    cout<<i<<" ";
	cout<<endl<<endl;
	
	cout<<"NUmber of all Possible Binary Tree with this Inorder Sequence : "<<Catalan(n)<<endl<<endl;
    
	vector<Node*> Tree = All_Possible_Inorder_Trees(in,0,n-1);  
    
	for (auto i:Tree) 
	BFT(i);
	
	return 0;
}
