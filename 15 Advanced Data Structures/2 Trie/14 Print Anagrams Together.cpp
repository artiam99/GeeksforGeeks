#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode* children[26];
    int index;
};
TrieNode* GetNode()
{
	TrieNode* Node = new TrieNode;
	
	for(int i = 0 ; i < 26 ; i++)
	Node->children[i] = NULL;
	
	Node->index = -1;
	
	return Node;
}
void Search(TrieNode* root , string &ana , vector<vector<string>> &ans , string &curr)
{
    for(int i = 0 ; i < ana.length() ; i++)
    {   
    	int index = ana[i] - 'a';
    
        if(!root->children[index])  root->children[index] = GetNode();
        
        root = root->children[index];
    }
    if(root->index == -1)
    {
        root->index = ans.size();
        
        ans.push_back(vector<string>());
    }
    ans[root->index].push_back(curr);
}
vector<vector<string>> Anagrams(vector<string> &a) 
{
    vector<vector<string>> ans;
    
    TrieNode* root = GetNode();
    
    int alpha[26];
    
    for(auto i : a)
    {
        memset(alpha,0,sizeof(alpha));
        
        for(int j = 0 ; j < i.length() ; j++)
        alpha[i[j]-'a']++;
        
        string ana;
        
        for(int j = 0 ; j < 26 ; j++)
        while(alpha[j]--)
        ana.push_back((char)(j+'a'));
        
        Search(root , ana , ans , i);
    }
    
    return ans;
}
signed main()
{	
	vector<string> dictionary = {"act" , "god" , "cat" , "dog" , "tac"};
	
	vector<vector<string>> Ana = Anagrams(dictionary);
	
	for(auto i : Ana)
	{
		for(auto j : i)
		cout << j << " ";
		cout << endl;
	}
	
	return 0;
}
