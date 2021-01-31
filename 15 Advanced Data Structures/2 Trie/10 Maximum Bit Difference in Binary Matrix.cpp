#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode* children[2];
    int leaf;
};
TrieNode* GetNode()
{
	TrieNode* Node = new TrieNode;
	
	for(int i = 0 ; i < 2 ; i++)
	Node->children[i] = NULL;
	
	return Node;
}
void Insert(TrieNode* root , vector<int> &a , int index)
{
    for(int i = 0 ; i < a.size() ; i++)
    {   
        if(!root->children[a[i]])  root->children[a[i]] = GetNode();
        
        root = root->children[a[i]];
    }
    root->leaf = index;
}
void Rec(TrieNode* root , vector<int> &a , int i , pair<int,int> &temp , int diff)
{
	if(i == a.size() && diff > temp.first)  temp = {diff , root->leaf};
	
	if(root->children[0])  Rec(root->children[0] , a , i + 1 , temp , diff + (a[i] != 0));
	
	if(root->children[1])  Rec(root->children[1] , a , i + 1 , temp , diff + (a[i] != 1));
}
void Max_Diff_Pair(vector<vector<int>> &a, int n)
{
	TrieNode* root = GetNode();
	
	Insert(root , a[0] , 1);
	
	int mx_diff = INT_MIN;
	
	pair<int,int> p , temp;
	
	temp.first = INT_MIN , temp.second = 1;
	
	for(int i = 1 ; i < n ; i++)
	{
		Rec(root , a[i] , 0 , temp , 0);
		
		if(temp.first > mx_diff)
		{
			mx_diff = temp.first;
			
			p = {temp.second , i+1};
		}
		
		Insert(root , a[i] , i+1);
	}
	
	cout << p.first << " " << p.second << endl;
}
signed main()
{	
	vector<vector<int>> a = { {1, 1, 1, 1},
							  {1, 0, 1, 1},
							  {0, 0, 0, 0} };
	int n = a.size();
	
	Max_Diff_Pair(a,n);
	
	return 0;
}
