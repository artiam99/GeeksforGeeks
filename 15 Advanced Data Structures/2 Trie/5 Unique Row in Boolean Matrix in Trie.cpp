#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
	TrieNode* Children[2];
	
	bool isleaf;
};
TrieNode* GetNode()
{
	TrieNode* Node = new TrieNode;
	
	for(int i = 0 ; i < 2 ; i++)
	Node->Children[i] = NULL;
	
	Node->isleaf = false;
	
	return Node;
}
void Insert(TrieNode* root , vector<int> &row)
{
	for(int i = 0 ; i < row.size() ; i++)
	{
		int index = row[i];
		
		if(!root->Children[index])  root->Children[index] = GetNode();
		
		root = root->Children[index];
	}
	
	if(!root->isleaf)
	{
		for(auto i : row)
		cout << i << " ";
		cout << endl;
	}
	
	root->isleaf = true;
}
void UniqueRow(vector<vector<int>> &a , int r , int c)
{
    TrieNode* root = GetNode();
    
    for(int i = 0 ; i < r ; i++)
    {
        vector<int> row;
        
        for(int j = 0 ; j < c ; j++)
        row.push_back(a[i][j]);
        
        Insert(root , row);
    }
}
signed main()
{	
	vector<vector<int>> a = { {1 , 1 , 0 , 1},
							  {1 , 0 , 0 , 1},
							  {1 , 1 , 0 , 1} };
	int r = a.size() , c = a[0].size();
	
	UniqueRow(a,r,c);
	
	return 0;
}
