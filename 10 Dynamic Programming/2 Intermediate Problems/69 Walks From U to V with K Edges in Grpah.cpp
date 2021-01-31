#include<bits/stdc++.h>
using namespace std;
int DFS(int u,int v,int k,vector<vector<bool>> &adj,vector<vector<int>> &dp)
{
    if(dp[u][k] != -1)  return dp[u][k];
    
    dp[u][k] = 0;
    
    if(k == 0) return dp[u][k] = ( (u == v) ? 1 : 0);
    
    for(int i=0;i<adj.size();i++)
    if(adj[u][i])
    dp[u][k] += DFS(i,v,k-1,adj,dp);
    
    return dp[u][k];
}
int countwalks(vector<vector<bool>> &adj, int  n, int u, int v, int k)
{
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	    
	return DFS(u,v,k,adj,dp);
}
signed main()
{
	vector<vector<bool>> adj = { { 0, 1, 1, 1 },
                        		 { 0, 0, 0, 1 },
                       		 	 { 0, 0, 0, 1 },
                        		 { 0, 0, 0, 0 } };
    int n = adj.size();
    
	int u = 0, v = 3, k = 2;
    
	cout << countwalks(adj, n, u, v, k);
    
	return 0;
}
