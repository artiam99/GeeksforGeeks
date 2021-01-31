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
void Rec(TrieNode* root , string &s)
{
	if(root->isleaf)  cout << s << endl;
	
	for(int i = 0 ; i < 26 ; i++)
	if(root->Children[i])
	{
		s.push_back('a' + i);
		
		Rec(root->Children[i] , s);
		
		s.pop_back();
	}
}
void Display(TrieNode* root)
{
	string s;
	
	Rec(root , s);
}
signed main()
{
	vector<string> a = {"the" , "a" , "there" , "answer" , "any" , "by" , "bye" , "their"};
	int n = a.size();
	
	TrieNode* root = GetNode();
	
	for(int i = 0 ; i < n ; i++)
	Insert(root , a[i]);
	
	Display(root);
	
	return 0;
}
