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
Node* construct(int in[],int lvl[],unordered_map<int,int> &m,int l,int r,int ind,int n)
{
    if(l>r)
    return NULL;
    
	while(ind<n&&(m[lvl[ind]]<l||m[lvl[ind]]>r))
    ind++;
    
	if(ind==n)
    return NULL;
    
    int i=m[lvl[ind]];
    
	Node* root=(Node*)malloc(sizeof(Node));
    root->key=lvl[ind++];
    
	root->left=construct(in,lvl,m,l,i-1,ind,n);
    
	root->right=construct(in,lvl,m,i+1,r,ind,n);
    
	return root;
}
Node* buildTree(int in[], int lvl[],int n)
{
    if(n==0)
    return NULL;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    m[in[i]]=i;
    return construct(in,lvl,m,0,n-1,0,n);
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
