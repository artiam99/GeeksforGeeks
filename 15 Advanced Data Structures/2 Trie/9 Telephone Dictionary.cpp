#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode* children[26];
    bool isleaf;
};
TrieNode* GetNode()
{
	TrieNode* Node = new TrieNode;
	
	for(int i = 0 ; i < 26 ; i++)
	Node->children[i] = NULL;
	
	Node->isleaf = false;
	
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
    root->isleaf = true;
}
void Rec(TrieNode* root , string &curr , int i , string &pat , vector<string> ans[])
{	
    if(root->isleaf)
    {
        for(int j = 0 ; j < i ; j++)
        ans[j].push_back(curr);
    }
    
    for(int j = 0 ; j < 26 ; j++)
    if(root->children[j])
    {
        curr += (char)(j + 'a');
        
        bool flag = (i < pat.length() && i == curr.length() - 1 && (j + 'a' == pat[i]));
        
        Rec(root->children[j] , curr , i + flag , pat , ans);
        
        curr.pop_back();
    }
}
void Telephone_Dictionary(TrieNode* root , string &pat)
{
	vector<string> ans[pat.length()];
	    
    string curr;
    
    Rec(root , curr , 0 , pat , ans);
    
    for(int i = 0 ; i < pat.length() ; i++)
    {
        if(!ans[i].size()) cout << 0;
        
        else
        for(auto j : ans[i])
        cout << j << " ";
        
        cout << endl;
    }
}
signed main()
{	
	vector<string> dictionary = {"geeikistest" , "geeksforgeeks" , "geeksfortest"};
	int n = dictionary.size();
	
	TrieNode* root = GetNode();
	
	for(auto i : dictionary)
	Insert(root , i);
	
	string pat = "geeips";
	
	Telephone_Dictionary(root , pat);
	
	return 0;
}
