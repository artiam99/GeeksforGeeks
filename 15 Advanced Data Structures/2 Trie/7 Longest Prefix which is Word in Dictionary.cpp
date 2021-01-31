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
string LongestPrefix(TrieNode* root , string s)
{
	string ans , curr;
	
	for(int i = 0 ; i < s.length() ; i++)
	{
		int index = s[i] - 'a';
		
		if(!root->Children[index])  return ans;
		
		curr += s[i];
		
		if(root->Children[index]->isleaf)  ans = curr;		
		
		root = root->Children[index];
	}
	
	return ans;
}
signed main()
{	
	vector<string> dictionary = {"are", "area", "base" , "cat" , "cater" , "children" , "basement"};
	int n = dictionary.size();
	
	TrieNode* root = GetNode();
	
	for(auto i : dictionary)
	Insert(root , i);
	
	string word = "basemax";
	
	cout << LongestPrefix(root , word) << endl;
	
	return 0;
}
