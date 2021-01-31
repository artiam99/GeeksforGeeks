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
	cout<<endl;
}
void rev(Node* root,int key,map<int,int> &m,int lvl,int &ind,bool &itr)
{
	if(!root)
	return;
	
	m[lvl]=root->data;
	
	if(root->data==key)
	itr=!itr;
	
	if(!itr)
	rev(root->left,key,m,lvl+1,ind,itr);
	
	if(!itr)
	rev(root->right,key,m,lvl+1,ind,itr);
	
	if(itr)
	root->data=m[ind++];
}
void Reversepath(Node* root,int key)
{
	map<int,int> m;
	cout<<endl<<"Path reversed"<<endl<<endl;
	int ind=0;
	bool itr=0;
	rev(root,key,m,0,ind,itr);
}
signed main()
{
	Node *root = new Node(1); 
  
    root->left        = new Node(2); 
    root->right       = new Node(3); 
  
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left  = new Node(6); 
    root->right->right = new Node(7); 
  
    root->left->left->left  = new Node(8); 
    root->left->left->right  = new Node(9); 
    root->left->right->left  = new Node(10); 
    root->left->right->right  = new Node(11); 
    root->right->left->left  = new Node(12); 
    root->right->left->right  = new Node(13); 
    root->right->right->left  = new Node(14); 
    root->right->right->right  = new Node(15); 
	BFT(root);
	Reversepath(root,13);
	BFT(root);
	Reversepath(root,6);
	BFT(root);
	Reversepath(root,8);
	BFT(root);
	return 0;
}
