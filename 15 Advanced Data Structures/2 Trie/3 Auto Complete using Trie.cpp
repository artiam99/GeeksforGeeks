#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
	TrieNode* Children[26];
	
	bool isleaf;
};
TrieNode* GetNode()
{
	TrieNode* Node = new TrieNode;
	
	for(int i = 0 ; i < 26 ; i++)
	Node->Children[i] = NULL;
	
	Node->isleaf = false;
	
	return Node;
}
void Insert(TrieNode* root , string key)
{
	for(int i = 0 ; i < key.length() ; i++)
	{
		int index = key[i] - 'a';
		
		if(!root->Children[index])  root->Children[index] = GetNode();
		
		root = root->Children[index];
	}
	root->isleaf = true;
}
void Auto_Complete(TrieNode* root , string key , int i)
{
	if(i >= key.length() && root->isleaf)  cout << key << endl;
	
	if(i < key.length())
	{
		int index = key[i] - 'a';
		
		if(root->Children[index])  Auto_Complete(root->Children[index] , key , i+1);
		
		return;
	}
	
	for(int j = 0 ; j < 26 ; j++)
	if(root->Children[j])
	{
		key.push_back(j + 'a');
		
		Auto_Complete(root->Children[j] , key , i+1);
		
		key.pop_back();
	}
}
signed main()
{	
	TrieNode* root = GetNode();
	
	Insert(root, "hello");
    Insert(root, "dog");
    Insert(root, "hell");
    Insert(root, "cat");
    Insert(root, "a");
    Insert(root, "hel");
    Insert(root, "help");
    Insert(root, "helps");
    Insert(root, "helping");
	
	Auto_Complete(root , "hel" , 0);
	
	return 0;
}
