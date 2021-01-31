#include<bits/stdc++.h>
using namespace std;
#define int uint64_t
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	int data;
	Node* left;
	Node* right;
	int count;
	Node(int x)
	{
		data=x;
		left=right=NULL;
		count=1;
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
	if(x<(*root)->data)
	insert(x,&((*root)->left));
	else if(x>(*root)->data)
	insert(x,&((*root)->right));
	else
	(*root)->count++;
}
void Diagonaltraversal(Node* root)
{
	vector<pair<int,int>> dia;
	
	queue<Node*> q;
	
	if(root);
	q.push(root);
	
	while(q.size())
	{
		root=q.front(); q.pop();
		
		while(root)
		{
			dia.push_back({root->data,root->count});
			
			if(root->left)
			q.push(root->left);
			
			root=root->right;
		}
	}
	for(auto i:dia)
	cout<<i.first<<"("<<i.second<<") ";
	cout<<endl;
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	Diagonaltraversal(root);
	return 0;
}
