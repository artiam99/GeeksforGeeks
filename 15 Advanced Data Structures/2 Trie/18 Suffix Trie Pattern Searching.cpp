#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
	TrieNode* children[26];
	
	bool isleaf;
	
	TrieNode()
	{
		for(int i = 0 ; i < 26 ; i++)
		children[i] = NULL;
		
		isleaf = false;
	}
};
void Insert(TrieNode* root , string s)
{
	for(int i = 0 ; i < s.length() ; i++)
	{
		int index = s[i] - 'a';
		
		if(!root->children[index])  root->children[index] = new TrieNode();
		
		root = root->children[index];
	}
	root->isleaf = true;
}
bool Trie_Search(TrieNode* root , string &pat , int m)
{
	for(int i = 0 ; i < m ; i++)
	{
		int index = pat[i] - 'a';
		
		if(!root->children[index])  return false;
		
		root = root->children[index];
	}
	return true;
}
bool Search(string &s , int n , string &pat , int m)
{
	TrieNode* root = new TrieNode;
	
	for(int i = 0 ; i < n ; i++)
	Insert(root , s.substr(i , n - i));
	
	return Trie_Search(root , pat , m);
}
signed main()
{	
	string s = "banana";
	int n = s.length();
	
	string pat = "ana";
	int m = pat.length();
	
	if(Search(s , n , pat , m))  cout << "Pattern Present" << endl;
	
	else  cout << "Pattern Not Present" << endl;
	
	return 0;
}
