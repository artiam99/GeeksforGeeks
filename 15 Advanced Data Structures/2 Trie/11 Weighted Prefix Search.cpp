#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode* children[26];
    bool leaf;
    int wt;
};
TrieNode* GetNode()
{
	TrieNode* Node = new TrieNode;
	
	for(int i = 0 ; i < 26 ; i++)
	Node->children[i] = NULL;
	
	Node->leaf = false;
	
	return Node;
}
void Insert(TrieNode* root , string &s , int wt)
{
    for(int i = 0 ; i < s.length() ; i++)
    {   
    	int index = s[i] - 'a';
    
        if(!root->children[index])  root->children[index] = GetNode();
        
        root = root->children[index];
    }
    root->leaf = true;
    root->wt = wt;
}
void Rec(TrieNode* root , string &pat , int i , int &wt , string &s , string &ans)
{
	if(i == pat.length() && root->leaf && wt < root->wt)
	{
		wt = root->wt;
		
		ans = s;
	}
	
	if(i < pat.length())
	{
		int index = pat[i] - 'a';
		
		s.push_back(pat[i]);
		
		if(root->children[index])  Rec(root->children[index] , pat , i+1 , wt , s , ans);
		
		s.pop_back();
		
		return;
	}
	
	for(int j = 0 ; j < 26 ; j++)
	if(root->children[j])
	{
		s.push_back(char(j+'a'));
		
		Rec(root->children[j] , pat , i , wt , s , ans);
		
		s.pop_back();
	}
}
string Max_Wt_String(TrieNode* root , string &pat)
{
	string s , ans;
	
	int wt = 0;
	
	Rec(root , pat , 0 , wt , s , ans);
	
	if(ans.size())  return ans;
	
	return "-1";
}
signed main()
{	
	vector<pair<string,int>> a = {{"geeks" , 15} , {"geeksfor" , 301} , {"geeksforgeeks" , 45}};
	int n = a.size();
	
	TrieNode* root = GetNode();
	
	for(int i = 0 ; i < n ; i++)
	Insert(root , a[i].first , a[i].second);
	
	string pat = "geek";
	
	cout << Max_Wt_String(root , pat) << endl;
	
	return 0;
}
