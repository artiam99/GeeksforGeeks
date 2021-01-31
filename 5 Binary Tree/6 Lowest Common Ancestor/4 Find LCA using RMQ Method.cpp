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
int RMQ(vector<int> &a,int al,int ar,int *st,int ql,int qr,int sti)
{
	if(al>=ql&&ar<=qr)
	return st[sti];
	
	if(al>qr||ar<ql)
	return -1;
	
	int m=al+(ar-al)/2;
	
	int i1=RMQ(a,al,m,st,ql,qr,sti*2+1);
	int i2=RMQ(a,m+1,ar,st,ql,qr,sti*2+2);
	
	if(i1==-1)
	return i2;
	
	if(i2==-1)
	return i1;
	
	return (a[i1]<a[i2])?i1:i2;
}
void constructuntill(vector<int> &a,int al,int ar,int *st,int sti)
{
	if(al==ar)
	{
		st[sti]=al;
		return;
	}
	
	int m=al+(ar-al)/2;
	constructuntill(a,al,m,st,sti*2+1);
	constructuntill(a,m+1,ar,st,sti*2+2);
	
	st[sti]=( a[st[sti*2+1]] < a[st[sti*2+2]] ) ? st[sti*2+1] : st[sti*2+2];
}
int* construct(vector<int> &a,int n)
{
	int p=ceil(log2(n));
	int size=2*pow(p,2)-1;
	
	int *st=new int[size];
	constructuntill(a,0,n-1,st,0);
	return st;
}
void make_euler_and_level_array(Node* root,vector<int> &E,vector<int> &L,int h=0)
{
	if(!root)
	return;
	
	E.push_back(root->data);
	L.push_back(h);
	
	if(root->left)
	{
		make_euler_and_level_array(root->left,E,L,h+1);
	
    	E.push_back(root->data);
    	L.push_back(h);
	}
	
	if(root->right)
	{
		make_euler_and_level_array(root->right,E,L,h+1);
	
     	E.push_back(root->data);
    	L.push_back(h);
	}
}
int findLCA(Node* root,vector<pair<int,int>> &p)
{
	vector<int> E,L;
	make_euler_and_level_array(root,E,L);// Euler's Tour
	
	unordered_map<int,int> m;// First Occurence Index Map
	
	for(int i=0;i<E.size();i++)
	if(m.find(E[i])==m.end())
	m[E[i]]=i;
	
	int *st=construct(L,L.size());
	
	for(auto i:p)
	{
		int l=m[i.first];
		int r=m[i.second];
		
		if(l>r)
		swap(l,r);
		
		int ind=RMQ(L,0,L.size()-1,st,l,r,0);
		
		cout<<"LCA of "<<i.first<<" and "<<i.second<<" is : "<<E[ind]<<endl<<endl;
	}
}
signed main()
{
	Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<pair<int,int>> p={{4,5},{4,6},{3,4},{2,4}};
    
    findLCA(root,p);
    
    return 0;
}
