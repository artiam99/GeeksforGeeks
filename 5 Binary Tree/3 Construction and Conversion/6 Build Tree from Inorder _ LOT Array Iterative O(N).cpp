#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	int key;
	Node* left;
	Node* right;
	Node(int x)
	{
		key=x;
		left=right=NULL;
	}
};
void insert(int x,Node** root)
{
	if(!(*root))
	{
		Node* temp=new Node(x);
		*root=temp;
		return;
	}
	if(x<=(*root)->key)
	insert(x,&((*root)->left));
	else if(x>(*root)->key)
	insert(x,&((*root)->right));
}

void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}
Node* buildTree(int in[], int lvl[],int n)
{
    if(n==0)
    return NULL;
    
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    m[in[i]]=i;
    
    queue<tuple<Node*,int,int>> q;
    
    Node* root=new Node(lvl[0]);
    
    q.push(make_tuple(root,intmin,intmax));
    
    int i=1;
     
    while(i<n)
	{
		Node* parent = get<0>(q.front());
		int left_lim = get<1>(q.front());
		int right_lim = get<2>(q.front());
		
		q.pop();
		
		if(left_lim < m[lvl[i]])
		{
			parent->left=new Node(lvl[i++]);
			q.push(make_tuple(parent->left,left_lim,m[parent->key]));
		}
		if(i<n && right_lim > m[lvl[i]])
		{
			parent->right=new Node(lvl[i++]);
			q.push(make_tuple(parent->right,m[parent->key],right_lim));
		}
	}
	return root;
}
signed main()
{
	int in[]={3, 1, 4 ,0 ,5 ,2 ,6};
	int lvl[]={0 ,1 ,2 ,3 ,4 ,5 ,6 };
	int n=sizeof(in)/sizeof(int);
	Node* root=buildTree(in,lvl,n);
	
	for(int i=0;i<n;i++)
	cout<<in[i]<<" ";cout<<endl;
	inorder(root);
	return 0;
}
