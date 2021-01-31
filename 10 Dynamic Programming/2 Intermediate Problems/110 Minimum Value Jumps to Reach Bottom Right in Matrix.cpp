#include<bits/stdc++.h>
using namespace std;
int MinJumps(vector<vector<int>> &a,int n,int m)
{
	vector<vector<int>>  dp(n,vector<int>(m,INT_MAX));
	
	dp[0][0] = 0;
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < m ; j++)
	if(dp[i][j] != INT_MAX)
	{	
		if(i + a[i][j] < n)  dp[i+a[i][j]][j] = min( dp[i+a[i][j]][j] , dp[i][j] + 1);
		
		if(j + a[i][j] < m)  dp[i][j+a[i][j]] = min( dp[i][j+a[i][j]] , dp[i][j] + 1);
	}
	
	if(dp[n-1][m-1] != INT_MAX)
	return dp[n-1][m-1];
	
	return -1;
}
signed main()
{
	vector<vector<int>> a = { {2, 3, 2, 1, 4},
                    		  {3, 2, 5, 8, 2},
                    		  {1, 1, 2, 2, 1}  };
	int n = a.size();
	int m = a[0].size();
	
	cout<< MinJumps(a,n,m) <<endl;
	
	return 0;
}
