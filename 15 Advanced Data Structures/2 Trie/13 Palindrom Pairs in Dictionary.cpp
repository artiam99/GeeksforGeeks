#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode* children[26];
    bool leaf;
};
TrieNode* GetNode()
{
	TrieNode* Node = new TrieNode;
	
	for(int i = 0 ; i < 26 ; i++)
	Node->children[i] = NULL;
	
	Node->leaf = false;
	
	return Node;
}
void Insert(TrieNode* root , string &s)
{
    for(int i = 0 ; i < s.length() ; i++)
    {   
    	int index = s[i] - 'a';
    
        if(!root->children[index])  root->children[index] = GetNode();
        
        root = root->children[index];
    }
    root->leaf = true;
}
bool Search(TrieNode* root , string &s)
{
	for(int i = s.length() - 1 ; i >= 0 ; i--)
	{
		int index = s[i] - 'a';
		
		if(!root->children[index])  return false;
		
		root = root->children[index];
	}
	return true;
}
bool Check(vector<string> &dictionary , int n)
{
	TrieNode* root = GetNode();
	
	for(auto i : dictionary)
	{
		if(Search(root , i))  return true;
		
		Insert(root , i);
	}
	
	return false;
}
bool Rec(TrieNode* curr , TrieNode* root , string &word , int i , bool flag)
{
	if(i == word.length())
	{
		if(curr->leaf && flag)  return true;
		
		return false;
	}
	
	if(curr->children[word[i] - 'a'])
	{
		if(!flag && Rec(root , root , word , i+1 , !flag))  return true;
		
		if(Rec(curr->children[word[i] - 'a'] , root , word , i+1 , flag))  return true;
	}
	
	return false;
}
signed main()
{	
	vector<string> dictionary = {"news" , "abcd" , "tree" , "geeks" , "paper"};
	int n = dictionary.size();
	
	TrieNode* root = GetNode();
	
	for(auto i : dictionary)
	Insert(root , i);
	
	string word = "newspaper";
	
	if(Rec(root , root , word , 0 , 0))  cout << "YES" << endl;
	
	else  cout << "NO" << endl;
	
	return 0;
}
