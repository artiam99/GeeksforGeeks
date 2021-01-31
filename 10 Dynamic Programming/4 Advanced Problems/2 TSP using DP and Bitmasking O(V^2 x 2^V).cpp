#include<bits/stdc++.h>
using namespace std;
int Shortest_Path(int V,vector<int> adj[],int u,int mask,vector<vector<int>> &dp)
{
	if(mask == (1 << V) - 1)  return adj[u][0];
	
	if(dp[mask][u] != -1)  return dp[mask][u];
	
	int ans = INT_MAX;
	
	for(int i = 0 ; i < V ; i++)
	if(!(mask & (1 << i)))
	ans = min(ans , adj[u][i] + Shortest_Path(V,adj,i, mask | (1 << i) , dp));
	
	return dp[mask][u] = ans;
}
int Shortest_Hamiltonian_Cycle(int V,vector<int> adj[])
{	
	vector<vector<int>> dp((1 << V) , vector<int>(V , -1));
	
	return Shortest_Path(V,adj,0,1,dp);
}
signed main()
{
	int V = 4;
	
	vector<int> adj[] = { {0, 10, 20, 12},
						  {10, 0, 15, 17},
					   	  {20, 15, 0, 11},
						  {12, 17, 11, 0} };  // Complete Graph
	
	cout << Shortest_Hamiltonian_Cycle(V,adj) << endl;
	
	return 0;
}
