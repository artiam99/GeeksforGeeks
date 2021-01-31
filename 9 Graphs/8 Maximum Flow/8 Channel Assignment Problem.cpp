#include<bits/stdc++.h>
using namespace std;

bool BFS(vector<vector<int>> &adj,int s,int t,vector<int> &parent)
{
	vector<bool> vis(adj.size());
	
	queue<int> q;
	
	q.push(s);
	vis[s]=true;
	parent[s]=-1;
	
	while(q.size())
	{
		int u=q.front(); q.pop();
		
		for(int i=0;i<adj.size();i++)
		if(!vis[i] && adj[u][i])
		{
			q.push(i);
			vis[i]=true;
			parent[i]=u;
		}
	}
	return vis[t];
}
int Maximum_Flow(vector<vector<int>> &adj,int s,int t)
{
	vector<int> parent(adj.size(),-1);
	
	int mx=0;
	
	while(BFS(adj,s,t,parent))
	{
		int path_flow=INT_MAX;
		
		for(int i=t;i!=s;i=parent[i])
		path_flow = min(path_flow , adj[parent[i]][i]);
		
		for(int i=t;i!=s;i=parent[i])
		{
			adj[parent[i]][i] -= path_flow;
			
			adj[i][parent[i]] += path_flow;
		}

		mx+=path_flow;
	}
	
	return mx;
}
int Maximum_Packet(int table[3][3],int m,int n)
{
    vector<vector<int>> adj(m+n+2,vector<int>(m+n+2,0));
    for(int i=1;i<=m;i++)
    adj[0][i]=INT_MAX;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(table[i][j])
            adj[i+1][j+m+1]=table[i][j];
        }
    }
    for(int i=0;i<n;i++)
    adj[i+m+1][m+n+1]=INT_MAX;
    
    return Maximum_Flow(adj,0,m+n+1);
}
signed main()
{
	int table[3][3] = {{0, 2, 0},
	                   {3, 0, 1}, 
					   {2, 4, 0} };
	
	
	cout<< Maximum_Packet(table,3,3) <<endl;
	
	return 0;
}
