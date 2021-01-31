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
bool Rec(TrieNode* root , string &s)
{
	if(root->isleaf)  return true;
	
	int cnt = 0;
	
	for(int i = 0 ; i < 26 ; i++)
	if(root->Children[i])  cnt++;
	
	for(int i = 0 ; i < 26 ; i++)
	if(root->Children[i])
	{
		s.push_back(i + 'a');
		
		if(Rec(root->Children[i] , s) && cnt > 1)
		cout << s << " ";
		
		s.pop_back();
	}
	
	return (cnt <= 1);
}
void Unique_Prefix(TrieNode* root)
{
	string s;
	
    Rec(root , s);
}
signed main()
{	
	vector<string> dictionary = {"zebra" , "dog" , "duck" , "dove"};
	int n = dictionary.size();
	
	TrieNode* root = GetNode();
	
	for(auto i : dictionary)
	Insert(root , i);
	
	Unique_Prefix(root);
	
	return 0;
}
