#include<bits/stdc++.h>
using namespace std;
int Largest_Sub_Matrix(vector<vector<int>> &a,int n,int m)
{
	vector<vector<pair<int,int>>> Sum(n,vector<pair<int,int>>(m));
	
	for(int i = 0 ; i < n ; i++)
	{
		int one = 0 , zero = 0;
		
		for(int j = 0 ; j < m ; j++)
		{
			if(a[i][j])
			one++;
			
			else
			zero++;
			
			Sum[i][j] = {one , zero};
		}
	}
	
	int mx = 0;
	
	for(int i = 0 ; i < m ; i++)
	for(int j = i ; j < m ; j++)
	{
		map<int,int> mp;
		
		mp[0] = -1;
		
		int one = 0 , zero = 0;
		
		for(int k = 0 ; k < n ; k++)
		{
			one += Sum[k][j].first - ((i==0) ? 0 : Sum[k][i-1].first);
			
			zero += Sum[k][j].second - ((i==0) ? 0 : Sum[k][i-1].second);
			
			if(mp.find(one-zero) == mp.end())
			mp[one-zero] = k;
			
			else
			mx = max(mx , (j-i+1) * (k-mp[one-zero]));
		}
	}
	return mx;
}
signed main()
{
	vector<vector<int>> a = { {0, 0, 1, 1},
                    		  {0, 1, 1, 0},
                    		  {1, 1, 1, 0},
                    		  {1, 0, 0, 1} };
    int n = a.size();
    int m = a[0].size();
    
    cout<< Largest_Sub_Matrix(a,n,m) <<endl;
    
	return 0;
}
