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
void insert(int x,Node** root)
{
	if(!(*root))
	{
		Node* temp=new Node(x);
		*root=temp;
		return;
	}
	if(x<=(*root)->data)
	insert(x,&((*root)->left));
	else
	insert(x,&((*root)->right));
}
void BFT(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(q.size())
	{
		Node* temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
	}
	cout<<endl;
}
void preorder(Node* root)
{
	if(!root)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(Node* root)
{
	if(!root)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int findmax(Node* root)
{
	if(!root)
	return -1;
	while(root->right)
	root=root->right;
	return root->data;
}
int findmin(Node* root)
{
	if(!root)
	return -1;
	while(root->left)
	root=root->left;
	return root->data;
}
int height(Node* root,int level)
{
	if(!root)
	return level;
	return max(height(root->left,level+1),height(root->right,level+1));
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
		if(!(*root)->left&&!(*root)->right)
		{
			delete *root;
			*root=NULL;
		}
		else if((*root)->left&&!(*root)->right)
		{
			Node* temp=(*root)->left;
			delete *root;
			*root=temp;
		}
		else if((*root)->right&&!(*root)->left)
		{
			Node* temp=(*root)->right;
			delete *root;
			*root=temp;
		}
		else
		{
			(*root)->data=findmin((*root)->right);
			Delete(&((*root)->right),(*root
			)->data);
		}
	}
}
signed main()
{
	Node* root=NULL;
	insert(12,&root);insert(17,&root);insert(8,&root);insert(13,&root);insert(11,&root);insert(7,&root);insert(9,&root);insert(8,&root);insert(12,&root);
	cout<<"Breadth Fisrt Traversal : ";BFT(root);cout<<endl;
	cout<<"Preorder Traversal : ";preorder(root);cout<<endl<<endl;
	cout<<"Inorder Traversal : ";inorder(root);cout<<endl<<endl;
	cout<<"Postorder Traversal : ";postorder(root);cout<<endl<<endl;
	cout<<"Max element and Min element : "<<findmax(root)<<"   "<<findmin(root)<<endl<<endl;
	cout<<"Height (Number of edges) : "<<height(root,-1)<<endl<<endl;
	cout<<"Delete 11 and first 8 ";Delete(&root,11);Delete(&root,8);cout<<endl<<endl;
	cout<<"Breadth Fisrt Traversal : ";BFT(root);cout<<endl;
	return 0;
}
