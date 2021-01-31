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
string Longest_Common_Prefix(TrieNode* root)
{
	string ans;
	
	while(1)
    {
        if(root->isleaf)  break;
        
        int cnt = 0 , index;
        
        for(int i = 0 ; i < 26 ; i++)
        if(root->Children[i])
        {
            index = i;
            
            cnt++;
        }
        
        if(cnt != 1)  break;
        
        ans += 'a' + index;
        
        root = root->Children[index];
    }
    
    if(!ans.size())  return "-1";
    
    return ans;
}
signed main()
{	
	vector<string> dictionary = {"geeks" , "geeksforgeeks" , "geesbees"};
	int n = dictionary.size();
	
	TrieNode* root = GetNode();
	
	for(auto i : dictionary)
	Insert(root , i);
	
	cout << Longest_Common_Prefix(root) << endl;
	
	return 0;
}
