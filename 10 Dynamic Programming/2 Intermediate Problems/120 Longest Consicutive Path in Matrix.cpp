#include<bits/stdc++.h>
using namespace std;
int DFS(vector<vector<int>> &a,int n,int m,int i,int j,vector<vector<bool>> &vis,vector<vector<int>> &dp)
{
	if(vis[i][j])  return dp[i][j];
	
	vis[i][j] = true;
	
	if(i > 0 && a[i-1][j] == a[i][j] + 1)  dp[i][j] = max(dp[i][j] , 1 + DFS(a,n,m,i-1,j,vis,dp));
	
	if(j > 0 && a[i][j-1] == a[i][j] + 1)  dp[i][j] = max(dp[i][j] , 1 + DFS(a,n,m,i,j-1,vis,dp));
	
	if(i < n-1 && a[i+1][j] == a[i][j] + 1)  dp[i][j] = max(dp[i][j] , 1 + DFS(a,n,m,i+1,j,vis,dp));
	
	if(j < m-1 && a[i][j+1] == a[i][j] + 1)  dp[i][j] = max(dp[i][j] , 1 + DFS(a,n,m,i,j+1,vis,dp));
	
	return dp[i][j];
}
int LongestPath(vector<vector<int>> &a,int n,int m)
{
	vector<vector<int>> dp(n,vector<int>(m,1));
	
	vector<vector<bool>> vis(n,vector<bool>(m));
	
	int mx = INT_MIN;
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < m ; j++)
	mx = max(mx , DFS(a,n,m,i,j,vis,dp));
		
	return mx;
}
signed main()
{
	vector<vector<int>> a = { {1, 2, 9},
                   			  {5, 3, 8},
                   			  {4, 6, 7} };
	int n = a.size();
	int m = a[0].size();
	
	cout<< LongestPath(a,n,m) <<endl;
	return 0;
}
