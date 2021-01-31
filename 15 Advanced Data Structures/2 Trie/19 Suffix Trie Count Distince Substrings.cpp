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
void Insert(TrieNode* root , string s , int &cnt)
{
	for(int i = 0 ; i < s.length() ; i++)
	{
		int index = s[i] - 'a';
		
		if(!root->children[index])  root->children[index] = new TrieNode() , cnt++;
		
		root = root->children[index];
	}
	root->isleaf = true;
}
int Count_Distinct_Sub_Str(string& s , int n)
{
	TrieNode* root = new TrieNode();
	
	int cnt = 1;
	
	for(int i = 0 ; i < n ; i++)
	Insert(root , s.substr(i , n - i) , cnt);
	
	return cnt;
}
signed main()
{	
	string s = "ababa";
	int n = s.length();
	
	cout << Count_Distinct_Sub_Str(s , n) << endl;
	
	return 0;
}
