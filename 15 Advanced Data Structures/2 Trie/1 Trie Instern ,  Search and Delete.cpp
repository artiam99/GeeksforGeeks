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
void Insert(TrieNode* root , string &key)
{
	for(int i = 0 ; i < key.length() ; i++)
	{
		int index = key[i] - 'a';
		
		if(!root->Children[index])  root->Children[index] = GetNode();
		
		root = root->Children[index];
	}
	root->isleaf = true;
}
bool Search(TrieNode* root , string key)
{
	for(int i = 0 ; i < key.length() ; i++)
	{
		int index = key[i] - 'a';
		
		if(!root->Children[index])  return false;
		
		root = root->Children[index];
	}
	return (root && root->isleaf);
}
bool Empty(TrieNode* root)
{
	for(int i = 0 ; i < 26 ; i++)
	if(root->Children[i])
	return false;
	
	return true;
}
TrieNode* Delete(TrieNode* root , string key , int i)
{
	if(!root)  return NULL;
	
	if(i == key.length())
	{
		root->isleaf = false;
		
		if(Empty(root))
		{
			delete root;
			
			root = NULL;
		}
		
		return root;
	}
	
	int index = key[i] - 'a';
	
	root->Children[index] = Delete(root->Children[index] , key , i + 1);
	
	if(Empty(root) && root->isleaf == false)
	{
		delete root;
		
		root = NULL;
	}
	
	return root;
}
signed main()
{
	vector<string> a = {"geek" , "geeksforgeeks" , "for"};
	int n = a.size();
	
	TrieNode* root = GetNode();
	
	for(int i = 0 ; i < n ; i++)
	Insert(root , a[i]);
	
	if(Search(root , "geeksforgeeks"))  cout << "YES" << endl;  else  cout << "NO" << endl;
	
	if(Search(root , "in"))  cout << "YES" << endl;  else  cout << "NO" << endl;
	
	root = Delete(root , "geeks" , 0);
	
	if(Search(root , "geeks"))  cout << "YES" << endl;  else  cout << "NO" << endl;
	
	return 0;
}
