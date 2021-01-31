#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node* left, *right;
};
struct Node* getNode(int data)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}
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
void inorder(Node* root,vector<int> &a)
{
	if(!root)
	return;
	inorder(root->left,a);
	a.push_back(root->data);
	inorder(root->right,a);
}
void replace(Node* root,vector<int> &a)
{
	static int ind=1;
	if(!root)
	return;
	replace(root->left,a);
	
	root->data=a[ind-1]+a[ind+1];
	ind++;
	
	replace(root->right,a);
}
void change(Node* root)
{
	vector<int> a;
	
	a.push_back(0);
	inorder(root,a);
	a.push_back(0);
	
	replace(root,a);
	
	cout<<endl;
}
int main()
{
	struct Node* root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	root->right->left = getNode(6);
	root->right->right = getNode(7);
	BFT(root);
	change(root);
	BFT(root);
	return 0;
}
