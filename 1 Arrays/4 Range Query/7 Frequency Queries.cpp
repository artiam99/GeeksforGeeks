#include<bits/stdc++.h> 
using namespace std;

void Frequency(vector<int> &a , int n , vector<pair<int,pair<int,int>>> &Q , int q)
{
	unordered_map<int,vector<int>> m;
	
	for(int i = 0 ; i < n ; i++)
	m[a[i]].push_back(i);
	
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].second.first - 1;
		int r = Q[i].second.second - 1;
		int val = Q[i].first;
		
		
		int low = lower_bound(m[val].begin() , m[val].end() , l) - m[val].begin();
		
		int high = upper_bound(m[val].begin() , m[val].end() , r) - m[val].begin();
		
		cout << high - low << endl;
	}
}

int main()
{
    vector<int> a = {2, 8, 6, 9, 8, 6, 8, 2, 11}; 
    int n = a.size();
    
	vector<pair<int,pair<int,int>>> Q = {{2 , {1 , 6}} , {8 , {4 , 9}}};
    int q = Q.size();
	
	Frequency(a , n , Q , q);
    
	return 0; 
}

