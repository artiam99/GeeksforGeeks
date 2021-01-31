#include <bits/stdc++.h>
using namespace std;
struct Node
{ 
	char key;
	
	vector<Node*> child;
	
	Node(char data)
	{
		key = data;
	}
};

int Depth(Node* root)
{
	if(!root)  return 0;
	
	int mx = 0;
	
	for(int i = 0 ; i < root->child.size() ; i++)
	mx = max(mx , Depth(root->child[i]));
	
	return mx + 1;
}

void DFS(Node* root)
{
	if(!root)  return;
	
	cout << root->key << " ";
	
	for(int i = 0 ; i < root->child.size() ; i++)
	DFS(root->child[i]);
}

int main()
{
	Node *root = new Node('A');
   (root->child).push_back(new Node('B'));
   (root->child).push_back(new Node('F'));
   (root->child).push_back(new Node('D'));
   (root->child).push_back(new Node('E'));
   (root->child[0]->child).push_back(new Node('K'));
   (root->child[0]->child).push_back(new Node('J'));
   (root->child[2]->child).push_back(new Node('G'));
   (root->child[3]->child).push_back(new Node('C'));
   (root->child[3]->child).push_back(new Node('H'));
   (root->child[3]->child).push_back(new Node('I'));
   (root->child[0]->child[0]->child).push_back(new Node('N'));
   (root->child[0]->child[0]->child).push_back(new Node('M'));
   (root->child[3]->child[2]->child).push_back(new Node('L'));
  
   cout << Depth(root) << endl;
   
   DFS(root);

	return 0;
}

