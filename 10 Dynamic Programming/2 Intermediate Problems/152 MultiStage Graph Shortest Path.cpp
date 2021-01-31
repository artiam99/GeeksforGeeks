#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int ShortestPath(vector<vector<int>> &adj,int n)
{
	int dist[n];
	
	for(int i = 0 ; i < n ; i++)
	dist[i] = INT_MAX;
	
	dist[0] = 0;
	
	queue<int> q;
	
	vector<bool> vis(n);
	
	q.push(0);
	vis[0] = true;
	
	while(q.size())
	{
		int u = q.front();  q.pop();
		
		for(int i = 0 ; i < n ; i++)
		{
			if(adj[u][i] != INF)
			{
				dist[i] = min(dist[i] , dist[u] + adj[u][i]);
				
				if(!vis[i])
				{
					q.push(i);
					vis[i] = true;
				}
			}
		}
	}
	
	return dist[n-1];
}
signed main()
{
	vector<vector<int>> adj = {{INF, 1  , 2  , 5  , INF, INF, INF, INF}, 
						       {INF, INF, INF, INF, 4  , 11 , INF, INF}, 
						       {INF, INF, INF, INF, 9  , 5  , 16 , INF}, 
						       {INF, INF, INF, INF, INF, INF, 2  , INF}, 
						       {INF, INF, INF, INF, INF, INF, INF, 18 }, 
						       {INF, INF, INF, INF, INF, INF, INF, 13 }, 
						       {INF, INF, INF, INF, INF, INF, INF, 2  },
							   {INF, INF, INF, INF, INF, INF, INF, INF} }; 
	int n = adj[0].size();
	
	cout<< ShortestPath(adj,n) <<endl;
	
	return 0;
}
