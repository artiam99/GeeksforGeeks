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
void change(Node* root)
{
	static Node* pre=NULL;
	static int p=0;
	
	if(!root)
	return;
	
	change(root->left);
	
	int d=root->data;
	if(pre)
	pre->data+=d;
	root->data=p;
	pre=root;
	p=d;
	
	change(root->right);
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
	cout<<endl;
	BFT(root);
	return 0;
}
