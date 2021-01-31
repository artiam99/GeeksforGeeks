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
int Rec(TrieNode* root , string &pat , int i , int dp[])
{
	if(i == pat.length())  return 0;
	
	if(dp[i] != -1)  return dp[i];
	
	dp[i] = 10000;
	
	TrieNode* curr = root;
	
	for(int j = i ; j < pat.length() ; j++)
	{	
		int index = pat[j] - 'a';
		
		if(!curr->Children[index])  return dp[i];
		
		if(curr->Children[index]->isleaf)  dp[i] = min(dp[i] , 1 + Rec(root , pat , j + 1 , dp));
		
		curr = curr->Children[index];
	}
	
	return dp[i];
}
int Min_Word_Break(TrieNode* root , string &pat)
{	
	int dp[pat.length()];  memset(dp , -1 , sizeof(dp));
	
	int mn = Rec(root , pat , 0 , dp);
	
	return ((mn == 10000) ? -1 : mn - 1);
}
signed main()
{	
	vector<string> dictionary = {"cat" , "mat" , "ca" , "tm" , "at" , "c" , "dog" , "og" , "do"};
	int n = dictionary.size();

	TrieNode* root = GetNode();
	
	for(int i = 0 ; i < n ; i++)
	Insert(root , dictionary[i]);
	
	string pat = "dogcat";
	
	cout << Min_Word_Break(root , pat) << endl;
	
	return 0;
}
