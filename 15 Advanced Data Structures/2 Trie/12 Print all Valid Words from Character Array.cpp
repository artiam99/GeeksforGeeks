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
void Rec(TrieNode* root , bool alpha[] , string &s)
{
	if(root->leaf)  cout << s << endl;
	
	for(int i = 0 ; i < 26 ; i++)
	if(root->children[i] && alpha[i])
	{
		s.push_back(char(i + 'a'));
		
		Rec(root->children[i] , alpha , s);
		
		s.pop_back();
	}
}
void All_Words(vector<string> &dictionary , int n , vector<char> &a , int m)
{
	TrieNode* root = GetNode();
	
	for(auto i : dictionary)
	Insert(root , i);
	
	bool alpha[26];  memset(alpha , 0 , sizeof(alpha));
	
	for(int i = 0 ; i < m ; i++)
	alpha[a[i] - 'a'] = true;
	
	string s;
	
	Rec(root , alpha , s);
}
signed main()
{	
	vector<string> dictionary = {"go" , "bat" , "me" , "eat" , "goal" , "boy" , "run"};
	int n = dictionary.size();
	
	vector<char> a = {'e','o','b', 'a','m','g', 'l'};
	int m = a.size();
	
	All_Words(dictionary , n , a , m);
	
	return 0;
}
