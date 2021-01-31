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
void store(Node* root,vector<int> &a,int l)//  Inorder
{
	if(!root)
	return;
	store(root->left,a,l+1);
	if(l%2==0)
	a.push_back(root->data);
	store(root->right,a,l+1);
}
void modify(Node* root,vector<int> &a,int l,int &ind)//  Inorder
{
	if(!root)
	return;
	modify(root->left,a,l+1,ind);
	if(l%2==0)
	root->data=a[ind--];
	modify(root->right,a,l+1,ind);
}
void Makespiral(Node* root)
{
	cout<<endl<<"Making Spiral "<<endl<<endl;
	if(!root)
	return;
	vector<int> a;
	store(root,a,1);
	int ind=a.size()-1;
	modify(root,a,1,ind);
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
  
    root->left->left->left->left  = new Node(16); 
    root->left->left->left->right  = new Node(17); 
    root->left->left->right->left  = new Node(18); 
    root->left->left->right->right  = new Node(19); 
    root->left->right->left->left  = new Node(20); 
    root->left->right->left->right  = new Node(21); 
    root->left->right->right->left  = new Node(22); 
    root->left->right->right->right  = new Node(23); 
    root->right->left->left->left  = new Node(24); 
    root->right->left->left->right  = new Node(25); 
    root->right->left->right->left  = new Node(26); 
    root->right->left->right->right  = new Node(27); 
    root->right->right->left->left  = new Node(28); 
    root->right->right->left->right  = new Node(29); 
    root->right->right->right->left  = new Node(30); 
    root->right->right->right->right  = new Node(31);

	BFT(root);
	Makespiral(root);
	BFT(root);
	return 0;
}
