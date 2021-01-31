#include<bits/stdc++.h> 
using namespace std;

void Sparse(vector<int> &a , int n , vector<pair<int,int>> &Q , int q)
{
    vector<vector<int>> lookup;
    
	for(int i = 0 ; i < n ; i++)
	{
	    lookup.push_back(vector<int>());
	    
		lookup[i].push_back(i);
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i + 1 ; j < n ; j++)
		{
			if(a[lookup[i][j-1-i]] < a[j])  lookup[i].push_back(lookup[i][j-1-i]);
			
			else  lookup[i].push_back(j);
		}
	}
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].first;
		int r = Q[i].second;
		
		cout << a[lookup[l][r-l]] << endl;
	}
}

int main() 
{ 
	vector<int> a = {7, 2, 3, 0, 5, 10, 3, 12, 18}; 
	int n = a.size(); 
	
	vector<pair<int,int>> Q = {{0 , 4} , {4 , 7} , {7 , 8}}; 
	int q = Q.size();
	
	Sparse(a , n , Q , q);
	
	return 0; 
} 

