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
struct node
{
	int data;
	node* prev,*next;
	node(int x)
	{
		data=x;
		prev=next=NULL;
	}
};
void traverse(Node* root,node* v)
{
	if(!root)
	return;
	
	v->data+=root->data;
	
	if(root->left)
	{
		if(!v->prev)
		{
			v->prev=new node(0);
			v->prev->next=v;
		}
		traverse(root->left,v->prev);
	}
	
	if(root->right)
	{
		if(!v->next)
		{
			v->next=new node(0);
			v->next->prev=v;
		}
		traverse(root->right,v->next);
	}
}
vector<int> verticalSumDLL(Node* root)
{
	vector<int> a;
	if(!root)
	return a;
	
	node* v=new node(0);
	
	traverse(root,v);
	
	while(v->prev)
	v=v->prev;
	
	while(v)
	{
		a.push_back(v->data);
		v=v->next;
	}
	
	return a;
}
signed main()
{
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 

    
	vector<int>a=verticalSumDLL(root);
    cout << "Vertical Sums are\n";
    for(auto i:a)
    cout<<i<<" ";
    cout<<endl;
    
    return 0;
}
