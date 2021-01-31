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
void BFT(Node* root)
{
	if(!root)
	{
		cout<<endl;
		return;
	}
	queue<Node*> q;
	q.push(root);
	while(q.size())
	{
		cout<<q.front()->data<<"("<<q.front()->count<<")"<<" ";
		if(q.front()->left)
		q.push(q.front()->left);
		if(q.front()->right)
		q.push(q.front()->right);
		q.pop();
	}
	cout<<endl;
}
int Findmax(Node* root)
{
	while(root->right)
	root=root->right;
	return root->data;
}
void Delete(Node** root,int x)
{
	if(!(*root))
	return;
	else if(x<(*root)->data)
	Delete(&((*root)->left),x);
	else if(x>(*root)->data)
	Delete(&((*root)->right),x);
	else
	{
		if((*root)->count>1)
		(*root)->count--;
		else
		{
			if(!(*root)->left&&!(*root)->right)
			{
				delete (*root);
				(*root)=NULL;
			}
			else if(!(*root)->left)
			{
				Node* temp=*root;
				*root=(*root)->right;
				delete temp;
			}
			else if(!(*root)->right)
			{
				Node* temp=*root;
				*root=(*root)->left;
				delete temp;
			}
			else
			{
				(*root)->data=Findmax((*root)->left);
				Delete(&((*root)->left),(*root)->data);
			}
		}
	}
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	cout<<"Breadth Fisrt Traversal : ";BFT(root);cout<<endl;
	cout<<"Delete 11 ";Delete(&root,11);cout<<endl<<endl;
	cout<<"Breadth Fisrt Traversal : ";BFT(root);cout<<endl;
	cout<<"Delete 12 ";Delete(&root,12);cout<<endl<<endl;
	cout<<"Breadth Fisrt Traversal : ";BFT(root);cout<<endl;
	cout<<"Delete 12 ";Delete(&root,12);cout<<endl<<endl;
	cout<<"Breadth Fisrt Traversal : ";BFT(root);cout<<endl;
	return 0;
}
